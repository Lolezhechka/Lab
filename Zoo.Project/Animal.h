#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "Date.h"
#include "spdlog/spdlog.h"

#include <string>

class Abstract_animal {
protected:
    char* nickName_;
    Date dateOfBirth_;
    std::shared_ptr<spdlog::logger> log_;
public:
    Abstract_animal() = delete;
    Abstract_animal(std::string nickName, Date dateOfBirth);
    Abstract_animal(const Abstract_animal&);
    Abstract_animal& operator=(const Abstract_animal&);
    Abstract_animal(Abstract_animal&&) noexcept ;
    Abstract_animal& operator=(Abstract_animal&&);
    ~Abstract_animal();

    std::string name() const noexcept;
    Date dateOfBirth() const noexcept;

    int age() const noexcept;
    int age(const Date& date) const noexcept;

    virtual std::string toString() const noexcept;

    //virtual std::string description() const = 0;

};

#endif  // ANIMAL_H