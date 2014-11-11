#ifndef PROJCG_INTERPOLATOR_H_
#define PROJCG_INTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "hdrimage.h"

class Interpolator {
public:
	Interpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval) :
		observations_(observations),
		values_(values),
		interval_(interval) {}
	virtual HdrImage calculateInterpolationOn(int observation) = 0;
	virtual HdrImage takeStep() = 0;
protected:
	std::vector<int> observations_;
	std::vector<HdrImage> values_;
	int interval_;
	int step = 0;
};

#endif