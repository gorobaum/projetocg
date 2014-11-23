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
	
	HdrImage one("blue.hdr");
	HdrImage two("red.hdr");
	HdrImage three("green.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	std::vector<int> observations;
	observations.push_back(2);
	observations.push_back(4);
	observations.push_back(6);
	/*
	LinearInterpolator li(observations, imagesToInterpolate, 1);
	HdrImage finalLi = li.calculateInterpolationOn(5);
	finalLi.saveImageAsPng("output-li.png");
	finalLi.saveImageAsHdr("output-li.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 1);
	HdrImage finalLgi = lgi.calculateInterpolationOn(5);
	finalLgi.saveImageAsPng("output-lg.png");
	finalLgi.saveImageAsHdr("output-lg.hdr");*/


	for(int i = -100; i <= 100; i++)
	{
		GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 2);
		std::string name;
		HdrImage finalGfi = gfi.calculateInterpolationOn(4.0+(2* ((float) (i/100.0))));
		name.erase();
		name.append("lgfipos");
		name.append(std::to_string(i));
		name.append(".png");
		finalGfi.saveImageAsPng(name);
		//finalGfi.saveImageAsHdr("output-lgfi.hdr");
	}
	//HdrImage finalGfi = gfi.calculateInterpolationOn(5);
	//finalGfi.saveImageAsPng("output-lgfi.png");
	//finalGfi.saveImageAsHdr("output-lgfi.hdr");
	/*
	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 2);
	HdrImage finalGbi = gbi.calculateInterpolationOn(5);
	finalGbi.saveImageAsPng("output-lgbi.png");
	finalGbi.saveImageAsHdr("output-lgbi.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 2);
	HdrImage finalSi = si.calculateInterpolationOn(5);
	finalSi.saveImageAsPng("output-lsi.png");
	finalSi.saveImageAsHdr("output-lsi.hdr");
	*/
	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}