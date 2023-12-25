#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>
#include "AppZoo.h"
#include "Animal.h"
#include "Date.h"


int AppZoo::run() const {
	appLog_->info("Application has started");

	try {
		std::vector<Animal*> animals_;

		animals_.push_back(new Animal("nick1", Date(2018, 5, 14)));
		animals_.push_back(new Animal("nick2", Date(2018, 12, 31)));
		

		Animal n1("nick9", Date(2018, 5, 14));
		
		
		std::vector<Date> dates_;
		std::vector<std::string> nickNames_;
		std::vector<int> ages_;
		Date current_{ 2023, 12, 23 };

		nickNames_.push_back("nick1");
		nickNames_.push_back("nick2");
		

		dates_.push_back(Date(2018, 5, 14));
		dates_.push_back(Date(2018, 12, 31));
		

		ages_.push_back(5); // Date(2018, 5, 14));
		ages_.push_back(4); // Date(2018, 12, 31));
		
		auto itDate = dates_.begin();
		auto itNickName = nickNames_.begin();

		for (auto& tmp : animals_) {
			std::cout << tmp->name() << tmp->dateOfBirth() << tmp->age(current_);
		}

		for (auto& tmp : animals_) {
			delete tmp;
		}

	}
	catch (const std::invalid_argument& ex) {
		appLog_->error(std::string(ex.what()));
	}

	appLog_->info("Application has finished");
	return 0;
}

AppZoo::AppZoo(spdlog::level::level_enum appLogLevel) {
	auto sinkConsole = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

	appLog_ = std::make_shared<spdlog::logger>("appLog", sinkConsole);
	animalLog_ = std::make_shared<spdlog::logger>("animalLog", sinkConsole);

	spdlog::register_logger(appLog_);
	spdlog::register_logger(animalLog_);

	appLog_->set_level(appLogLevel);
	animalLog_->set_level(appLogLevel);
	std::string logPattern = "[%H:%M:%S] [%n] [%^---%L---%$] %v";
	appLog_->set_pattern(logPattern);
	animalLog_->set_pattern(logPattern);
}

// может выбрасить исключение при работе с файлом логирования spdlog::spdlog_ex
AppZoo::AppZoo(const std::string& logPath, spdlog::level::level_enum appLogLevel) {
	auto sinkConsole = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto sinkFile = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath, true);

	appLog_ = std::make_shared<spdlog::logger>("appLog", spdlog::sinks_init_list({ sinkConsole, sinkFile }));
	animalLog_ = std::make_shared<spdlog::logger>("animalLog", spdlog::sinks_init_list({ sinkConsole, sinkFile }));

	spdlog::register_logger(animalLog_);
	spdlog::register_logger(appLog_);

	appLog_->set_level(appLogLevel);
	animalLog_->set_level(appLogLevel);
	std::string logPattern = "[%YY-%m-%d] [%H:%M:%S] [%n] [%^---%L---%$] %v";
	appLog_->set_pattern(logPattern);
	animalLog_->set_pattern(logPattern);
}

AppZoo::~AppZoo() {
	// удаление логеров
	spdlog::drop_all();
}