#include <cmath>

#include "lagrangeinterpolator.h"

HdrImage LaGrangeInterpolator::takeStep() {
	FIBITMAP macaco;
	HdrImage interpolation(&macaco);
	step++;
	return interpolation;
}

HdrImage LaGrangeInterpolator::calculateInterpolationOn(double observation) {
	int numberOfObservations = observations_.size();
	int middle = std::floor(numberOfObservations/2);
	double medianObservation = observations_[middle];
	double p = (observation-medianObservation)/interval_;
	FIBITMAP macaco;
	HdrImage interpolation(&macaco);
	return interpolation;
}