#ifndef PROJCG_GAUSSIANFORWARDINTERPOLATOR_H_
#define PROJCG_GAUSSIANFORWARDINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"
#include "hdrimage.h"

class GaussianForwardInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	HdrImage takeStep(float observation);
	GaussianForwardInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval);

private:
};

#endif