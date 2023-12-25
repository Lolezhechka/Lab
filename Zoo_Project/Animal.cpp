#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
#include "spdlog/spdlog.h"

#include <string>
#include <sstream>

#include "Date.h"
#include "Animal.h"

Animal::Animal(std::string nickName, Date dateOfBirth): dateOfBirth_(dateOfBirth), log_(spdlog::get("animalLog")) {
	log_->trace("Aminal Ctor");
	nickName_ = new char[nickName.size() + 1];
	...
}
Animal::~Animal() {
	log_->debug("Aminal Dtor");
	...
}




