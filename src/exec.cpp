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
#include "exec.h"

int ext1(int argc, char** argv) 
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

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("ext1lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext1forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext1backward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("ext1stirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int ext2(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("ang8.hdr");
	HdrImage two("ang10.hdr");
	HdrImage three("ang12.hdr");
	HdrImage four("ang14.hdr");
	HdrImage five("ang16.hdr");
	HdrImage six("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	observations.push_back(180);
	observations.push_back(240);
	observations.push_back(300);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(150);
	finalLi.saveImageAsHdr("ext2linear.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(150);
	finalLgi.saveImageAsHdr("ext2lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(150);
	finalGfi.saveImageAsHdr("ext2forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(150);
	finalGbi.saveImageAsHdr("ext2backward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(150);
	finalSi.saveImageAsHdr("ext2stirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int ext3(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("ang14.hdr");
	HdrImage two("ang16.hdr");
	HdrImage three("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(90);
	finalLi.saveImageAsHdr("ext3linear.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("ext3lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext3forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext3backward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("ext3stirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int int1(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("ang14.hdr");
	HdrImage two("ang16.hdr");
	HdrImage three("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(90);
	finalLi.saveImageAsHdr("int1linear.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("int1lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("int1forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("int1backward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("int1stirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int int2(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("ang12.hdr");
	HdrImage two("ang14.hdr");
	HdrImage three("ang16.hdr");
	HdrImage four("ang18.hdr");

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
	finalLi.saveImageAsHdr("int2linear.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("int2lagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("int2forward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("int2backward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("int2stirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int focustest(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage one("ang13.hdr");
	HdrImage two("ang15.hdr");
	HdrImage three("ang17.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	
	LinearInterpolator li(observations, imagesToInterpolate, 60);
	HdrImage finalLi = li.calculateInterpolationOn(90);
	finalLi.saveImageAsHdr("focuslinear.hdr");

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 60);
	HdrImage finalLgi = lgi.calculateInterpolationOn(90);
	finalLgi.saveImageAsHdr("focuslagrange.hdr");

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("focusforward.hdr");

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("focusbackward.hdr");

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("focusstirling.hdr");

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}
