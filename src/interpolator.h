#ifndef PROJCG_INTERPOLATOR_H_
#define PROJCG_INTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

#include "hdrimage.h"

class Interpolator {
public:
	Interpolator(std::vector<double> observations, std::vector<HdrImage> values, double interval) :
		observations_(observations),
		values_(values),
		interval_(interval) {}
	virtual HdrImage calculateInterpolationOn(double observation) = 0;
	virtual HdrImage takeStep() = 0;
protected:
	std::vector<double> observations_;
	std::vector<HdrImage> values_;
	double interval_;
	int step = 0;
};

#endif