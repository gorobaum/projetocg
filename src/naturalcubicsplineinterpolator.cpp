#include <cmath>
#include <iostream>
#include <omp.h>
#include "naturalcubicsplineinterpolator.h"
#include "minmax.h"


#define Epsilon 0.001

NaturalCubicSplineInterpolator::NaturalCubicSplineInterpolator(std::vector<int> observations, std::vector<HdrImage> values) :
	Interpolator(observations, values){}



void SolveTriDiagonalSystem(int imgWidth, int imgHeight, std::vector<float> m, std::vector<float> h, std::vector<HdrImage> &dy2, std::vector<HdrImage> p)
{
	int n = p.size();
	double **Matrix;
	Matrix = (double **)malloc(sizeof(double *)*n);
	for(int i = 0; i < n; i++)
	{
		Matrix[i] = (double *)malloc(sizeof(double)*n);
		for(int j = 0; j < n; j++)
		{
			if(i == j) Matrix[i][j] = m[i];
			else if(i == (j+1)) Matrix[i][j] = h[i];
			else if(i == (j-1) && i+1 < n) Matrix[i][j] = h[i+1];
			else Matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		double r;
		r = Matrix[i+1][i]/Matrix[i][i];
		p[i+1] = p[i+1]-p[i]*r;
		Matrix[i+1][i] = Matrix[i+1][i]-Matrix[i][i]*r;
		Matrix[i+1][i+1] = Matrix[i+1][i+1]-Matrix[i][i+1]*r;
	}
	for(int i = n-1; i >= 0; i--)
	{
		double r;
		r = 1.0f/Matrix[i][i];
		p[i] = p[i]*r;
		Matrix[i][i] = Matrix[i][i]*r;
		if(i > 0)
		{
			r = Matrix[i-1][i];
			Matrix[i-1][i] = Matrix[i-1][i]-Matrix[i][i]*r;
			p[i-1] = p[i-1]-p[i]*r;
		} 
	}

	for(int i = 0; i < n; i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);

	dy2.clear();
	dy2.push_back(HdrImage(imgWidth, imgHeight));
	for(int i = 0; i < n; i++)
	{
		dy2.push_back(p[i]);
	}
	dy2.push_back(HdrImage(imgWidth,imgHeight));
}

HdrImage NaturalCubicSplineInterpolator::calculateInterpolationOn(float observation) {
	int numberOfObservations = observations_.size();
	int width = values_[0].getWidth();
	int height = values_[0].getHeight();
	HdrImage interpolation(width, height);

	std::vector<HdrImage> k, p, dy2;
	std::vector<float> h,m; 


	for(int i = 0; i < numberOfObservations-1; i++)
	{
		HdrImage tempImg(width,height);
		tempImg = values_[i+1]-values_[i];

		h.push_back(observations_[i+1]-observations_[i]);
		k.push_back(tempImg);
	}

	for(int i = 0; i < numberOfObservations-2; i++)
	{
		HdrImage tempImg(width,height);
		tempImg = ((k[i+1]/h[i+1])-(k[i]/h[i]))*6.0f;
		
		m.push_back(2.0*(h[i]+h[i+1]));
		p.push_back(tempImg);
	}
	

	SolveTriDiagonalSystem(width, height, m, h, dy2, p);

	int count = 0;
	if ((observation >= observations_.front()) && (observation <= observations_.back()) && (observations_.size() >= 4))
	{
		while(observation > observations_[count+1]) count++;
	}


	float temp = (observations_[count+1]-observation)*(observations_[count+1]-observation)*(observations_[count+1]-observation)/(6.0*h[count]);
	interpolation = dy2[count]*temp;

	temp = (observation-observations_[count])*(observation-observations_[count])*(observation-observations_[count])/(6.0*h[count]);
	interpolation = interpolation + dy2[count+1]*temp;

	temp = (observations_[count+1]-observation);
	interpolation = interpolation + ((values_[count]/h[count])-(dy2[count]*h[count])/6.0)*temp;

	temp = (observation-observations_[count]);
	interpolation = interpolation + ((values_[count+1]/h[count])-(dy2[count+1]*h[count])/6.0)*temp;


	interpolation = interpolation.clamp();

	return interpolation;
}