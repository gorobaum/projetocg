#ifndef PROJCG_GAUSSINTERPOLATOR_H_
#define PROJCG_GAUSSINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"
#include "hdrimage.h"

class GaussianInterpolator : public Interpolator {
using Interpolator::Interpolator;
public:
	HdrImage calculateInterpolationOn(float observation);
	HdrImage takeStep(float observation);
	GaussianInterpolator(std::vector<int> observations, std::vector<HdrImage> values);

private:
	double p;
};

#endif