#include "stats.h"
#include <math.h>

using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<float>& v) {
	Stats statistics;
	statistics.ComputeAverage(v);
	statistics.ComputeMax(v);
	statistics.ComputeMin(v);
	return statistics;
}