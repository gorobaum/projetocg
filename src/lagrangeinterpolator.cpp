#include <cmath>
#include <iostream>

#include "lagrangeinterpolator.h"

LaGrangeInterpolator::LaGrangeInterpolator(const std::vector<int> &observations, const std::vector<HdrImage> &values, int interval) :
	Interpolator(observations, values, interval){}

HdrImage LaGrangeInterpolator::calculateInterpolationOn(float observation) {
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	for (unsigned int i = 0;  i < observations_.size(); i++, step++) {
		int currentX = observations_[step];
		float numerator = 1.0, denominator = 1.0;
		for (unsigned int i = 0; i < observations_.size(); i++) {
			if ( i == step ) continue;
			numerator *= (observation - observations_[i]);
			denominator *= (currentX - observations_[i]);
		}
		interpolation = interpolation + values_[step]*(numerator/denominator);
	}
	interpolation = interpolation.clamp();
	return interpolation;
}