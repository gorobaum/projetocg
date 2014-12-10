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
	for (int i = 30; i <= 270; i+=1) {
		LinearInterpolator li(observations, imagesToInterpolate, 60);
		HdrImage finalLi = li.calculateInterpolationOn(i);
		std::string filenamePng("ext1linear");
		pol.addNewObservation(finalLi, i);
	}

	pol.printObservationsForPlot("observationsLinear.dat");


	PixelObserver polg(10,10);
	for (int i = 30; i <= 270; i+=1) {
		LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
		HdrImage finalLgi = lgi.calculateInterpolationOn(i);
		polg.addNewObservation(finalLgi, i);
	}

	polg.printObservationsForPlot("observationsLaGrange.dat");

	PixelObserver pogf(10,10);
	for (int i = 30; i <= 270; i+=1) {
		GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
		HdrImage finalGfi = gfi.calculateInterpolationOn(i);
		pogf.addNewObservation(finalGfi, i);
	}

	pogf.printObservationsForPlot("observationsFoward.dat");


	PixelObserver pogb(10,10);
	for (int i = 30; i <= 270; i+=1) {
		GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
		HdrImage finalGbi = gbi.calculateInterpolationOn(i);
		pogb.addNewObservation(finalGbi, i);
	}
	pogb.printObservationsForPlot("observationsBackward.dat");
	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
};
