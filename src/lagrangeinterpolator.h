#ifndef PROJCG_LAGRANGEINTERPOLATOR_H_
#define PROJCG_LAGRANGEINTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "interpolator.h"

class LaGrangeInterpolator : public Interpolator {
public:
	HdrImage calculateInterpolationOn(int observation);
	HdrImage takeStep();
};

#endif