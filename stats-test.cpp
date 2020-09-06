#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
	auto computedStats = Statistics::ComputeStatistics({ 1.5f, 8.9f, 3.2f, 4.5f });
	float epsilon = 0.001;
	REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
	REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
	REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
	auto computedStats = Statistics::ComputeStatistics({});
	REQUIRE(std::isnan(computedStats.average) == 1);
	REQUIRE(std::isnan(computedStats.max) == 1);
	REQUIRE(std::isnan(computedStats.min) == 1);
}

TEST_CASE("reports average from partial arrays") {
	auto computedStats = Statistics::ComputeStatistics({ 2.3f, 4.5f, NAN, 1.2f, 6.7f });
	float epsilon = 0.001;
	REQUIRE(std::abs(computedStats.average - 3.675) < epsilon);
	REQUIRE(std::abs(computedStats.max - 6.7) < epsilon);
	REQUIRE(std::abs(computedStats.min - 1.2) < epsilon);
}