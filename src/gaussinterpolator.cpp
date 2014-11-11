#include <cmath>

#include "gaussinterpolator.h"

FIRGBAF GaussianInterpolator::takeStep() {
	FIRGBAF interpolation;
	step++;
	return interpolation;
}

FIRGBAF GaussianInterpolator::calculateInterpolationOn(double observation) {
	int numberOfObservations = observations_.size();
	int middle = std::floor(numberOfObservations/2);
	double medianObservation = observations_[middle];
	double p = (observation-medianObservation)/interval_;
	FIRGBAF interpolation;
	return interpolation;
}