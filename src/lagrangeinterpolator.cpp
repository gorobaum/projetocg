#include <cmath>
#include <iostream>

#include "lagrangeinterpolator.h"

LaGrangeInterpolator::LaGrangeInterpolator(const std::vector<int> &observations, const std::vector<HdrImage> &values, int interval) :
	Interpolator(observations, values, interval){}

HdrImage LaGrangeInterpolator::takeStep(float observation) {
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	int currentX = observations_[step];
	float numerator = 1.0, denominator = 1.0;
	for (unsigned int i = 0; i < observations_.size(); i++) {
		if ( i == step ) continue;
		numerator *= (observation - observations_[i]);
		denominator *= (currentX - observations_[i]);
	}
	interpolation = values_[step]*(numerator/denominator);
	step++;
	return interpolation;
}

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
	std::cout << "LAGRANGE\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).red << "\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).green << "\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).blue << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).red << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).green << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).blue << "\n";
	interpolation = interpolation.clamp();
	return interpolation;
}