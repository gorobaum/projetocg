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
	
	HdrImage one("ang11.hdr");
	HdrImage two("ang13.hdr");
	HdrImage three("ang15.hdr");
	HdrImage four("ang17.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	observations.push_back(180);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(90);
	finalLi.saveImageAsHdr("ext1linear.hdr");
	finalLi.saveImageAsPng("ext1linear.png");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("ext1lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext1forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext1backward.hdr");

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}