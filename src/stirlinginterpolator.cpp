#include <cmath>
#include <iostream>
#include "stirlinginterpolator.h"
#include "gaussianbackwardinterpolator.h"
#include "gaussianforwardinterpolator.h"
#include "minmax.h"

HdrImage StirlingInterpolator::calculateForwardInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	if(observation < observations_[0] || observation > observations_[numberOfObservations-1])
	{
		std::cout << "Observation out of bounds.\n";
		return interpolation;
	}
	int x0 = 0;
	int xpos = numberOfObservations;
	int xneg = -1;
	for(int i = 0; (i < numberOfObservations && observations_[i] <= observation); i++)
	{
		x0 = i;
		xpos--;
		xneg++;
	}
	if(x0+1 < numberOfObservations && min(xpos,xneg) < min(xpos-1, xneg+1))
	{
		x0 = x0+1;
		xpos--;
		xneg++;
	}
	double p = (observation-observations_[x0])/(1.0*interval_);
	int dist = xpos;
	if(xneg < dist) dist = xneg;
	std::vector<std::vector<HdrImage>> dy;
	for(int i = 0; i < 2*dist+1; i++)
	{
		std::vector<HdrImage> v;
		dy.push_back(v);
		for(int j = 0; j < 2*dist+1-i; j++)
		{
			dy[i].push_back(HdrImage(width, height));
			if(i == 0)	dy[i][j] = values_[x0-dist+j];
			else dy[i][j] = dy[i-1][j+1]-dy[i-1][j];
		}
	}
	int denominator = 1;
	double numerator = p;
	int sign = -1;
	int counter = 0;
	interpolation = values_[x0];
	for(int i = 1; i < 2*dist+1; i++)
	{
		denominator = denominator*i;
		interpolation = interpolation + (dy[i][(int)floor((2*dist-i)/2.0)]*(numerator/denominator));
		sign = -sign;
		if(sign == 1) counter++;
		numerator = numerator*(p+sign*counter);
	}
	interpolation = interpolation.clamp();

	return interpolation;
}


HdrImage StirlingInterpolator::calculateBackwardInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	if(observation < observations_[0] || observation > observations_[numberOfObservations-1])
	{
		std::cout << "Observation out of bounds.\n";
		return interpolation;
	}
	int x0 = 0;
	int xpos = numberOfObservations;
	int xneg = -1;
	for(int i = 0; (i < numberOfObservations && observations_[i] <= observation); i++)
	{
		x0 = i;
		xpos--;
		xneg++;
	}
	if(x0+1 < numberOfObservations && min(xpos,xneg) < min(xpos-1, xneg+1))
	{
		x0 = x0+1;
		xpos--;
		xneg++;
	}
	double p = (observation-observations_[x0])/(1.0*interval_);
	int dist = xpos;
	if(xneg < dist) dist = xneg;
	std::vector<std::vector<HdrImage>> dy;
	for(int i = 0; i < 2*dist+1; i++)
	{
		std::vector<HdrImage> v;
		dy.push_back(v);
		for(int j = 0; j < 2*dist+1-i; j++)
		{
			dy[i].push_back(HdrImage(width, height));
			if(i == 0)	dy[i][j] = values_[x0-dist+j];
			else dy[i][j] = dy[i-1][j+1]-dy[i-1][j];
		}
	}
	int denominator = 1;
	double numerator = p;
	int sign = -1;
	int counter = 0;
	interpolation = values_[x0];
	for(int i = 1; i < 2*dist+1; i++)
	{
		denominator = denominator*i;
		interpolation = interpolation + (dy[i][(int)floor((2*dist-i)/2.0)]*(numerator/denominator));
		sign = -sign;
		if(sign == 1) counter++;
		numerator = numerator*(p+sign*counter);
	}
	interpolation = interpolation.clamp();

	return interpolation;
}


StirlingInterpolator::StirlingInterpolator(std::vector<int> observations, std::vector<HdrImage> values, int interval) :
	Interpolator(observations, values, interval){}

HdrImage StirlingInterpolator::calculateInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);
	HdrImage gf(width, height);
	HdrImage gb(width, height);
	GaussianForwardInterpolator gfi(observations_, values_, interval_);
	GaussianBackwardInterpolator gbi(observations_, values_, interval_);
	gf = gfi.calculateInterpolationOn(observation);
	gb = gbi.calculateInterpolationOn(observation);
	interpolation = gf*0.5 + gb*0.5;
	interpolation = interpolation.clamp();
	return interpolation;
}