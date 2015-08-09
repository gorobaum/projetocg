#ifndef PROJCG_NATURALCUBICSPLINE_H_
#define PROJCG_NATURALCUBICSPLINE_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"

class NaturalCubicSplineInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	NaturalCubicSplineInterpolator(std::vector<int> observations, std::vector<HdrImage> values);

};

#endif