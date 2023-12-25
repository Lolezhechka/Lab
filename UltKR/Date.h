#pragma once

#ifndef DATE_H
#define DATE_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>
#include <tuple>
#include <cstdint>

class Date {
public:
    // TODO определить конструкторы и деструктор, один уже указан
    Date(int year, int month = 1, int day = 1);
   

    Date operator+(int days) const;
    Date operator-(int days) const;

// TODO перегрузить операторы сравнения


    int day() const noexcept; // возвращает день
    int month() const noexcept;
    int year() const noexcept;
    int age() const noexcept; // возраст существа, на сегодня, если *this - дата отсчета
    int age(const Date& date) const noexcept; // возраст существа, на date, если *this - дата отсчета
 

    static bool isLeapYear(int year)  noexcept;
    static int daysInMonth(int year, int month) noexcept; количество дней в месяце
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