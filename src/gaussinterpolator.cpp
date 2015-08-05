#include <cmath>

#include "gaussinterpolator.h"

GaussianInterpolator::GaussianInterpolator(std::vector<int> observations, std::vector<HdrImage> values) :
	Interpolator(observations, values),
	p(0.0){}


HdrImage GaussianInterpolator::takeStep(float observation) {
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);

	step++;
	return interpolation;
}

HdrImage GaussianInterpolator::calculateInterpolationOn(float observation) {
	int interval_ = observations_[1]-observations_[0];

	int numberOfObservations = observations_.size();
	int middle = std::floor(numberOfObservations/2);
	double medianObservation = observations_[middle];
	p = (observation-medianObservation)/interval_;
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	return interpolation;
}