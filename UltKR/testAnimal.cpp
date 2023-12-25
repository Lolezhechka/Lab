#include "pch.h"
#include <gtest/gtest.h>
#include "../9901-kr2-zoo-forStuds/Date.h"
#include "../9901-kr2-zoo-forStuds/Animal.cpp"

namespace zootest {
	class AnimalFixture : public ::testing::Test {
	protected:
		void SetUp() override {
			...
		}

		void TearDown() override {
			...
		}

		std::vector<Animal*> animals_;
		std::vector<Date> dates_;
		std::vector<std::string> nickNames_;
		std::vector<int> ages_;
		Date current_{ 2023, 12, 23 };
		
	};

	TEST_F(AnimalFixture, TestCtorAnimal)
	{
		auto itDate = dates_.begin();
		auto itNickName = nickNames_.begin();

		ASSERT_EQ(dates_.size(), animals_.size());
		ASSERT_EQ(dates_.size(),nickNames_.size());

		...
	}

	TEST_F(AnimalFixture, TestAnimalAge)
	{
		auto itAge = ages_.begin();
		
		ASSERT_EQ(ages_.size(), animals_.size());

		...
	}


}