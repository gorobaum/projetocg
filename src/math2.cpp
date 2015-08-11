#include <cmath>
#include <iostream>

#include <vector>
#include "math2.h"


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

double quadraticRootBetween0And1(double a, double b, double c)
{
	double delta = b*b-4*a*c;
	double ret = (-b+sqrt(delta))/(2.0*a);
	if(!(ret > 0 && ret < 1))  ret = (-b-sqrt(delta))/(2.0*a);
	return ret;

}