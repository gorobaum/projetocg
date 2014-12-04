#include <cmath>
#include <iostream>
#include "stirlinginterpolator.h"
#include "gaussianbackwardinterpolator.h"
#include "gaussianforwardinterpolator.h"

StirlingInterpolator::StirlingInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval) :
	Interpolator(observations, values, interval){}

HdrImage StirlingInterpolator::calculateInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	HdrImage gf(width, height);
	HdrImage gb(width, height);
	GaussianBackwardInterpolator gfi(observations_, values_, interval_);
	GaussianBackwardInterpolator gbi(observations_, values_, interval_);
	gf = gfi.calculateInterpolationOn(observation);
	gb = gbi.calculateInterpolationOn(observation);
	interpolation = gf*0.5 + gb*0.5;
	interpolation = interpolation.clamp();
	return interpolation;
}