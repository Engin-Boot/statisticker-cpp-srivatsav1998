#include <vector>
#include <algorithm>
#include <math.h>
namespace Statistics {
	class Stats
	{
	public:
		float average;
		float max;
		float min;
		void ComputeAverage(const std::vector<float>& v)
		{
			if (v.empty())
				average = NAN;
			else {
				float sum = 0.0;
				int count = 0;
				for (int i = 0; i < v.size(); i++)
				{
					if (std::isnan(v[i]) != 1)
					{
						sum += v[i];
						count += 1;
					}
				}
				average = sum / count;
			}

		}
		void ComputeMin(const std::vector<float>& v)
		{
			if (v.empty())
				min = NAN;
			else
				min = *std::min_element(v.begin(), v.end());
		}
		void ComputeMax(const std::vector<float>& v)
		{
			if (v.empty())
				max = NAN;
			else
				max = *std::max_element(v.begin(), v.end());
		}

	};
	Stats ComputeStatistics(const std::vector<float>& v);
}