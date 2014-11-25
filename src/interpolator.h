#ifndef PROJCG_INTERPOLATOR_H_
#define PROJCG_INTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "hdrimage.h"

class Interpolator {
public:
	Interpolator(const std::vector<int> &observations, const std::vector<HdrImage> &values, int interval) :
		observations_(observations),
		values_(values),
		interval_(interval),
		step(0) {}
	virtual HdrImage calculateInterpolationOn(float observation) = 0;
	virtual HdrImage takeStep(float observation) = 0;
protected:
	std::vector<int> observations_;
	std::vector<HdrImage> values_;
	int interval_;
	unsigned int step;
};

#endif