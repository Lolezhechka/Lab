#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>

#include "AppZoo.h"

int main() {
    int status = -1;
    try {
        // Например, 
       auto appLogLevel = spdlog::level::trace;
       // AppZoo app("logs/applog.txt", appLogLevel);
        AppZoo app(appLogLevel);
        status = app.run();
    }
    catch (const spdlog::spdlog_ex& ex)
    {

        std::cerr << "Log init failed: " << ex.what() << std::endl;
    }

    return status;
}



