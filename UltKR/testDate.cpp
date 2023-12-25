#include "pch.h"
#include <gtest/gtest.h>
#include "../9901-kr2-zoo-forStuds/Date.cpp"

namespace zootest {
	class DateFixture : public ::testing::Test {
	protected:
		void SetUp() override {
			dates_.push_back(new Date(2023, 12, 14));
			

			listDates_.push_back({ 2023, 12, 14 });
			listDates_.push_back({ 2018, 12, 31 });
			

		}

		void TearDown() override {
			for (auto& tmp : dates_) {
				delete tmp;
			}
		}

		std::vector<Date*> dates_;
		std::vector<std::tuple<int, int, int>> listDates_;
		
	};

	TEST_F(DateFixture, TestCtorDate)
	{
		ASSERT_EQ(dates_.size(), listDates_.size());

		...
	}
	TEST_F(DateFixture, TestCtorDateWrong)
	{
		EXPECT_THROW(Date(2000, 2, 30), std::invalid_argument);
		
	}

	TEST_F(DateFixture, TestToString) {
		EXPECT_EQ(Date(2023, 12, 14).toString(), "2023-12-14");
		...
	}
	TEST_F(DateFixture, TestIsLeapYear) {
		EXPECT_TRUE(...);
		
			
		EXPECT_FALSE(...);
		
	}

	TEST_F(DateFixture, TestDaysInMonth) {
		EXPECT_EQ(Date::daysInMonth(2023, 1), 31);
		...
	
	}
	TEST_F(DateFixture, TestAddDays) {
		Date* date = new Date(2023, 12, 14);
		Date expected1(2023, 12, 15);
		

		EXPECT_EQ(*date + 1, expected1);
		
	}

	TEST_F(DateFixture, TestSubtractDays) {
		Date* date = new Date(2024, 5, 14);
		Date expected_1(2024, 5, 13);
		...

		EXPECT_EQ(*date - 1, expected_1);
		...
	}

	TEST_F(DateFixture, TestDaysComparisonOperators) {

		Date d11(2024, 2, 29);
		Date d22(2024, 2, 29);
		Date d33(2026, 1, 1);

		EXPECT_TRUE(d11 == d22);
		EXPECT_FALSE(d11 == d33);

		...
}

	TEST_F(DateFixture, TestAge) {
		Date birthDate(1990, 1, 1);
		Date date1(2023, 12, 31);
		...
	}
}