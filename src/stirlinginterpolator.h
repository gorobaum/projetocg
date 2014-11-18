#ifndef PROJCG_STIRLINGINTERPOLATOR_H_
#define PROJCG_STIRLINGINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"
#include "hdrimage.h"

class StirlingInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	HdrImage takeStep(float observation);
	StirlingInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval);

private:
};

#endif