#ifndef PROJCG_INTERPOLATOR_H_
#define PROJCG_INTERPOLATOR_H_

#include <vector>
#include <FreeImage.h>

class Interpolator {
public:
	Interpolator(std::vector<double> observations, std::vector<FIBITMAP*> values, double interval) :
		observations_(observations),
		values_(values),
		interval_(interval) {}
	virtual FIRGBAF calculateInterpolationOn(double observation) = 0;
	virtual FIRGBAF takeStep() = 0;
protected:
	std::vector<double> observations_;
	std::vector<FIBITMAP*> values_;
	double interval_;
	int step = 0;
};

#endif