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
#include "pixelobserver.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("black.hdr");
	HdrImage two("blue.hdr");
	HdrImage three("red.hdr");
	HdrImage four("green.hdr");
	HdrImage five("white.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);

	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(90);
	observations.push_back(150);
	observations.push_back(210);
	observations.push_back(270);
	
	PixelObserver pol(10,10);

	for (int i = 30; i <= 270; i+=10) {
		LinearInterpolator li(observations, imagesToInterpolate, 60);
		HdrImage finalLi = li.calculateInterpolationOn(i);
		std::string filenamePng("ext1linear");
		filenamePng += std::to_string(i)+".png";
		finalLi.saveImageAsHdr("ext1linear.hdr");
		finalLi.saveImageAsPng(filenamePng);
		pol.addNewObservation(finalLi, i);
	}

	pol.printObservationsForPlot("observationsLinear.dat");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("ext1lagrange.hdr");
	finalLgi.saveImageAsPng("ext1lagrange.png");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext1forward.hdr");
	finalLgi.saveImageAsPng("ext1forward.png");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext1backward.hdr");
	finalLgi.saveImageAsPng("ext1backward.png");

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
};
