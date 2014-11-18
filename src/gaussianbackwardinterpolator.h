#ifndef PROJCG_GAUSSIANBACKWARDINTERPOLATOR_H_
#define PROJCG_GAUSSIANBACKWARDINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"
#include "hdrimage.h"

class GaussianBackwardInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	HdrImage takeStep(float observation);
	GaussianBackwardInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval);

private:
};

#endif