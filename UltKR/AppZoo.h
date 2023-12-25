#pragma once
#ifndef APP_ZOO_H
#define APP_ZOO_H

#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>


class AppZoo
{
public:
	AppZoo(spdlog::level::level_enum appLogLevel = spdlog::level::debug);
	AppZoo(const std::string& logPath, spdlog::level::level_enum appLogLevel = spdlog::level::debug);
	~AppZoo();
	int run() const; // опционально - нужен для проверки работы функций, если нет тестирования
private:
	std::shared_ptr<spdlog::logger> appLog_;
	std::shared_ptr<spdlog::logger> animalLog_;

};
#endif //APP_ZOO_H
