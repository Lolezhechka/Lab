#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <memory>
#include <exception>
#include <sstream>
#include <ctime>

#include "Date.h"

Date::Date(int year, int month, int day) : year_(year) {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("The date is incorrect");
    }
    int days_in_month = daysInMonth(year, month);
    if (day > days_in_month || day < 1) {
        throw std::invalid_argument("The date is incorrect");
    }

    month = month_;
    day_ = day;
}

int Date::month() const noexcept {
    return month_;
}

int Date::year() const noexcept {
    return year_;
}

int Date::age() const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    Date today(local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    return this->age(today);
}

int Date::age(const Date& date) const noexcept {
    return inDays(date) - inDays(*this);
}

std::string Date::toString() const noexcept {
    std::ostringstream out("");
    out << day_ << "." << month_ << "." << year_;

    return out.str();
}
bool Date::isLeapYear(int year) noexcept {
    if (year % 4 == 0) {
        if (year % 100) {
            return year % 400;
        }
        return true;
    }
    return false;
}

int Date::daysInMonth(int year, int month) noexcept {
    int result{};
    if (month == 2 && isLeapYear(year)) {
        ++result;
    }
    result += MonthDays[month];
    return result;
}

Date Date::daysToDate(int days) noexcept {
    int year = days % 365;
    int leap_year_count = ((year / 4) + (year / 400) - (year / 100));
    days /= 365;
    days -= leap_year_count;

    int month = 1;
    for (int i{0}; i < MonthDays.size() && days > 28; ++i) {
        month++;
        days -= MonthDays[i];
    }
    int day = days;

    return Date(year, month, day);
}

int Date::inDays(const Date& date) noexcept {
    const int& year = date.year_;
    const int& month = date.month_;
    const int& day = date.day_;

    int leap_year_count{};
    int year_count{};
    int day_count{};

    leap_year_count += ((year / 4) + (year / 400) - (year / 100));
    year_count = year - leap_year_count;
    day_count = 366 * leap_year_count + year_count * 365;

    for (int i = 0; i != month; i++) {
        day_count += MonthDays[i];
    }
    if (((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) && month > 2) {
        day_count++;
    }
    day_count += day;
    return day_count;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}

std::istream& operator>>(std::istream& in, Date& date) {
    in >> date.day_ >> date.month_ >> date.year_;
    return in;
}

Date Date::operator+(int days) const {
    return daysToDate(inDays(*this) + days);
}

Date Date::operator-(int days) const {
    return daysToDate(inDays(*this) - days);
}


bool Date::operator<(const Date& rhs) const {
    return inDays(*this) < inDays(*this);
}

bool Date::operator>(const Date& rhs) const {
    return inDays(*this) > inDays(*this);
}

bool Date::operator==(const Date& rhs) const {
    return inDays(*this) == inDays(*this);
}

bool Date::operator>=(const Date& rhs) const {
    return inDays(*this) >= inDays(*this);
}

bool Date::operator<=(const Date& rhs) const {
    return inDays(*this) <= inDays(*this);
}

    