#include <cmath>
#include <iostream>

#include "quadraticinterpolator.h"
#include "lagrangeinterpolator.h"

QuadraticInterpolator::QuadraticInterpolator(const std::vector<int> &observations, const std::vector<HdrImage> &values) :
	Interpolator(observations, values){}

HdrImage QuadraticInterpolator::calculateInterpolationOn(float observation) {
	int count = 0;
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	if ((observation >= observations_.front()) && (observation <= observations_.back()) && (observations_.size() >= 3)) {
		if (observations_[0] == observation) return values_[0];
		if (observations_[observations_.size()-1] == observation) return values_[observations_.size()-1];
		while (observations_[count] < observation) count++;
		if(count == 0) count++;
		if(count == observations_.size()-1) count--;

		std::vector<int> quadraticObservations;
		std::vector<HdrImage> quadraticValues;

		quadraticObservations.push_back(observations_[count-1]);
		quadraticObservations.push_back(observations_[count]);
		quadraticObservations.push_back(observations_[count+1]);

		quadraticValues.push_back(values_[count-1]);
		quadraticValues.push_back(values_[count]);
		quadraticValues.push_back(values_[count+1]);

		LaGrangeInterpolator la(quadraticObservations, quadraticValues);

		interpolation = la.calculateInterpolationOn(observation);
	}
	interpolation = interpolation.clamp();
	return interpolation;
}