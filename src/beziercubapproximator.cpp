#include <cmath>
#include <iostream>

#include "bezier.h"
#include "beziercubapproximator.h"

BezierCubicApproximator::BezierCubicApproximator(const std::vector<int> &observations, const std::vector<HdrImage> &values) :
	Interpolator(observations, values){}

HdrImage BezierCubicApproximator::calculateInterpolationOn(float observation) {
	int count = 0;
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	std::vector<int> quadraticObservations;
	std::vector<HdrImage> quadraticValues;
	HdrImage interpolation(width, height);

	//std::cout << interpolation.getPixelAt(0,0).blue << std::endl;

	interpolation = interpolation.clamp();
	return interpolation;
}