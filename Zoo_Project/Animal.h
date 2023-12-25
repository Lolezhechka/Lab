#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <string>
#include "Date.h"

class Animal {
public:
    Animal() = delete;
    Animal(std::string nickName, Date dateOfBirth);
    Animal(const Animal&) ;
    Animal& operator=(const Animal&);
    Animal(Animal&&) ;
    Animal& operator=(Animal&&);
    ~Animal();

    std::string name() const noexcept;
    Date dateOfBirth() const noexcept;

    int age() const noexcept; // возраст животного на сегодня, если *this - дата отсчета
    int age(const Date& date) const noexcept; // возраст животного, на date, если *this - дата отсчета

    virtual std::string toString() const noexcept;

   // virtual std::string description() const = 0;

   protected:
        char* nickName_;
        Date dateOfBirth_;
        std::shared_ptr<spdlog::logger> log_;
    };

#endif //ANIMAL_H


