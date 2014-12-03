#include <cmath>
#include <iostream>

#include "linearinterpolator.h"

LinearInterpolator::LinearInterpolator(const std::vector<int> &observations, const std::vector<HdrImage> &values, int interval) :
	Interpolator(observations, values, interval){}

HdrImage LinearInterpolator::takeStep(float observation) {
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	return interpolation;
}

HdrImage LinearInterpolator::calculateInterpolationOn(float observation) {
	int count = 0;
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	if ((observation >= observations_.front()) && (observation <= observations_.back())) {
		while (observations_[count] < observation) count++;
		if (observations_[0] == observation) return values_[0];
		float denominator = 1.0*(observation-observations_[count-1])/(observations_[count]-observations_[count-1]);

		interpolation = values_[count-1]+(values_[count] - values_[count-1])*denominator;
	}
	std::cout << "LINEAR\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).red << "\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).green << "\n";
	std::cout << "interpolation[695][390] = " << interpolation.getPixelAt(695,390).blue << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).red << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).green << "\n";
	std::cout << "interpolation[696][390] = " << interpolation.getPixelAt(696,390).blue << "\n";
	interpolation = interpolation.clamp();
	return interpolation;
}