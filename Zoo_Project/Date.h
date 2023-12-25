#pragma once

#ifndef DATE_H
#define DATE_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>
#include <tuple>
#include <cstdint>

const std::vector<int> MonthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
public:
    Date(int year, int month, int day);

    Date operator+(int days) const;
    Date operator-(int days) const;

    bool operator>(const Date& rhs) const;
    bool operator<(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;

    int day() const noexcept;
    int month() const noexcept;
    int year() const noexcept;
    int age() const noexcept;  // возраст существа, на сегодня, если *this - дата отсчета
    int age(
            const Date& date) const noexcept;  // возраст существа, на date, если *this - дата отсчета

    static Date daysToDate(int days) noexcept;
    static int inDays(const Date& date) noexcept;
    static bool isLeapYear(int year) noexcept;
    static int daysInMonth(int year, int month) noexcept;  // количество дней в месяце
    std::string toString() const noexcept;

private:
    int day_;
    int month_;
    int year_;

    std::shared_ptr<spdlog::logger> log_;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};

#endif //DATE_H