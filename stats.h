#include <vector>
#include <algorithm>
#include <math.h>
namespace Statistics {
	class Stats
	{
    private:
        std::vector<float> removeNanValues(const std::vector<float>& v){
            std::vector<float> nonEmpty;
            
            for(int i=0; i<v.size(); i++){
                if(std::isnan(v[i]) != 1)
                    nonEmpty.push_back(v[i]);
            }
            return nonEmpty;
        }
	public:
		float average;
		float max;
		float min;
		void ComputeAverage(const std::vector<float>& v)
		{
			if (v.empty())
            {
				average = NAN;
            }
            std::vector<float> nonEmpty;
            nonEmpty = removeNanValues(v);
            float sum = 0.0;
            for (int i = 0; i < nonEmpty.size(); i++)
            {
                sum += nonEmpty[i];
            }
            average = sum / nonEmpty.size();
        

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