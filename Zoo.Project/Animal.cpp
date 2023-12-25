#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
#include "spdlog/spdlog.h"

#include <string>
#include <sstream>

#include "Date.h"
#include "Animal.h"

Abstract_animal::Abstract_animal(std::string Name, Date dateOfBirth)
        : dateOfBirth_(dateOfBirth), log_(spdlog::get("animalLog")) {
    log_->trace("Aminal Ctor");

    nickName_ = new char[Name.size() + 1];
    char* cstr = new char[Name.length() + 1];
    strcpy(cstr, Name.c_str());
}

Abstract_animal::~Abstract_animal() {
    log_->debug("Aminal Dtor");
    delete[] nickName_;
}

Abstract_animal::Abstract_animal(const Abstract_animal& animal)
        : dateOfBirth_(animal.dateOfBirth_), log_(spdlog::get("animalLog")) {
    if (this == &animal) {
        *this = animal;
    }
}

Abstract_animal& Abstract_animal::operator=(const Abstract_animal& animal) {
    delete[] nickName_;
    nickName_ = new char[strlen(animal.nickName_) + 1];
    strcpy(nickName_, animal.nickName_);
    dateOfBirth_ = animal.dateOfBirth_;

    return *this;
}

Abstract_animal::Abstract_animal(Abstract_animal&& animal) noexcept
        : dateOfBirth_(animal.dateOfBirth_), log_(spdlog::get("animalLog")) {
    *this = animal;
}

Abstract_animal& Abstract_animal::operator=(Abstract_animal&& animal) {
    std::swap(nickName_, animal.nickName_);
    std::swap(dateOfBirth_, animal.dateOfBirth_);

    return *this;
}

std::string Abstract_animal::name() const noexcept {
    std::string result(nickName_);
    return result;
}

Date Abstract_animal::dateOfBirth() const noexcept {
    return dateOfBirth_;
}

int Abstract_animal::age() const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    Date today(local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday);

    return this->age(today);
}

int Abstract_animal::age(const Date &date) const noexcept {
    return Date::inDays(date) - Date::inDays(dateOfBirth_);
}

std::string Abstract_animal::toString() const noexcept {
    std::ostringstream out("");
    out << name() << std::endl << dateOfBirth_;

    return out.str();
}
