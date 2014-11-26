#ifndef PROJCG_LINEARINTERPOLATOR_H_
#define PROJCG_LINEARINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"

class LinearInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	HdrImage takeStep(float observation);
	LinearInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval);
};

#endif