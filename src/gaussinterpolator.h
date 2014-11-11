#ifndef PROJCG_GAUSSINTERPOLATOR_H_
#define PROJCG_GAUSSINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"

class GaussianInterpolator : public Interpolator {
public:
	FIRGBAF calculateInterpolationOn(double observation);
	FIRGBAF takeStep();
};

#endif