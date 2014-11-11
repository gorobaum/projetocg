#include <cmath>

#include "gaussinterpolator.h"

HdrImage GaussianInterpolator::takeStep() {
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	step++;
	return interpolation;
}

HdrImage GaussianInterpolator::calculateInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int middle = std::floor(numberOfObservations/2);
	double medianObservation = observations_[middle];
	double p = (observation-medianObservation)/interval_;
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	return interpolation;
}