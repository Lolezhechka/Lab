#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <memory>
#include <exception>
#include <sstream>
#include <ctime>

#include "Date.h"

...

int Date::age() const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    Date today(local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    return this->age(today);
}

int Date::age(const Date& date) const noexcept {
    int age ...
...
    return age;
}

std::string Date::toString() const noexcept {
    std::stringstream ss;
    ..
    return ..
}
bool Date::isLeapYear(int year) noexcept {
   ...
}

int Date::daysInMonth(int year, int month) noexcept {
  ...
}


Date Date::operator+(int days) const {
    ...
    return result;
}

Date Date::operator-(int days) const {
   ...
    return result;
}


bool Date::operator<(const Date& rhs) const {
// можно использовать std::tie

    return ...
}
...

std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date.toString() ;
        return os;
    }

std::istream& operator>>(std::istream& is, Date& date) {
      ...
        return is;
    }

    