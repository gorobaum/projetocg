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
	observations.push_back(30);
	observations.push_back(90);
	observations.push_back(150);
	observations.push_back(210);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(120);
	finalLi.saveImageAsHdr("ext1linear.hdr");
	finalLi.saveImageAsPng("ext1linear.png");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(120);
	finalLgi.saveImageAsHdr("ext1lagrange.hdr");
	finalLgi.saveImageAsPng("ext1lagrange.png");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(120);
	finalGfi.saveImageAsHdr("ext1forward.hdr");
	finalLgi.saveImageAsPng("ext1forward.png");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(120);
	finalGbi.saveImageAsHdr("ext1backward.hdr");
	finalLgi.saveImageAsPng("ext1backward.png");

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}