#include <vector>
#include <algorithm>
#include <math.h>
namespace Statistics {
	struct Stats {
		float average = NAN;
		float max = NAN;
		float min = NAN;
	};

	Stats ComputeStatistics(const std::vector<float>& v);
}