#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <FreeImage.h>

#include "linearinterpolator.h"
#include "lagrangeinterpolator.h"
#include "gaussianforwardinterpolator.h"
#include "gaussianbackwardinterpolator.h"
#include "stirlinginterpolator.h"
#include "hdrimage.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage zero("black.hdr");
	HdrImage one("blue.hdr");
	HdrImage two("red.hdr");
	HdrImage three("green.hdr");
	HdrImage four("white.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(zero);
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(2);
	observations.push_back(4);
	observations.push_back(6);
	observations.push_back(8);
	
	int i = 0;
	int interval = 0;
	std::string name;
	if(argc > 3) 
	{
		i = atoi(argv[1]);
		interval = atoi(argv[2]);
		name = argv[3];
	}
	else return 1;

	HdrImage image(1,1);

	if(name == "li")
	{
		LinearInterpolator li(observations, imagesToInterpolate, interval);
		image = li.calculateInterpolationOn(2.0*(float)i/100.0);
	}
	else if(name == "la")
	{
		LaGrangeInterpolator lgi(observations, imagesToInterpolate, interval);
		image = lgi.calculateInterpolationOn(2.0*(float)i/100.0);
	}
	else if(name == "gf")
	{
		GaussianForwardInterpolator gfi(observations, imagesToInterpolate, interval);
		image = gfi.calculateInterpolationOn(2.0*(float)i/100.0);
	}
	else if(name == "gb")
	{
		GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, interval);
		image = gbi.calculateInterpolationOn(2.0*(float)i/100.0);
	}
	else if(name == "si")
	{
		StirlingInterpolator si(observations, imagesToInterpolate, interval);
		image = si.calculateInterpolationOn(2.0*(float)i/100.0);
	}

	name.append(std::to_string(i));
	name.append(".hdr");
	image.saveImageAsHdr(name);

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}