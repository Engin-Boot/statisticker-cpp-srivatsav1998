#include "stats.h"
#include <math.h>
#include <vector>

using namespace Statistics;

std::vector<float> removeNanValues(const std::vector<float>& v) {
	std::vector<float> nonEmpty;

	for (int i = 0; i<v.size(); i++) {
		if (std::isnan(v[i]) != 1)
			nonEmpty.push_back(v[i]);
	}
	return nonEmpty;
}

float ComputeMax(const std::vector<float>& values)
{
	float val = *std::max_element(values.begin(), values.end());
	return val;
}

float ComputeMin(const std::vector<float>& values)
{
	float val = *std::min_element(values.begin(), values.end());
	return val;
}

float ComputeAverage(const std::vector<float>& values)
{
	std::vector<float> nonEmpty;
	nonEmpty = removeNanValues(values);
	float sum = 0.0;
	for (int i = 0; i < nonEmpty.size(); i++)
	{
		sum += nonEmpty[i];
	}
	return (sum / nonEmpty.size());
}

Stats Statistics::ComputeStatistics(const std::vector<float>& v) 
{
	Stats statistics;
	if (!v.empty()) {
		statistics.average = ComputeAverage(v);
		statistics.max = ComputeMax(v);
		statistics.min = ComputeMin(v);
	}
	return statistics;
}