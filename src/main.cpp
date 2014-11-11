#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <FreeImage.h>

#include "linearinterpolator.h"
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
	HdrImage final = li.calculateInterpolationOn(2);
	final.saveImageAsPng("output.png");
	final.saveImageAsHdr("output.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}