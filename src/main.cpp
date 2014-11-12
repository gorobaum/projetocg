#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <FreeImage.h>

#include "linearinterpolator.h"
#include "lagrangeinterpolator.h"
#include "hdrimage.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("blue.hdr");
	HdrImage two("red.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);

	std::vector<int> observations;
	observations.push_back(2);
	observations.push_back(4);

	LinearInterpolator li(observations, imagesToInterpolate, 1);
	HdrImage finalLi = li.calculateInterpolationOn(3.5);
	finalLi.saveImageAsPng("output-li.png");
	finalLi.saveImageAsHdr("output-li.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 1);
	HdrImage finalLgi = lgi.calculateInterpolationOn(3.5);
	finalLgi.saveImageAsPng("output-lg.png");
	finalLgi.saveImageAsHdr("output-lg.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}