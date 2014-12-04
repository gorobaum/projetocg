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
	
	HdrImage base("ang14.hdr");

	HdrImage i7("ang7.hdr");
	HdrImage i8("ang8.hdr");
	HdrImage i9("ang9.hdr");
	HdrImage i10("ang10.hdr");
	HdrImage i11("ang11.hdr");
	HdrImage i12("ang12.hdr");
	HdrImage i13("ang13.hdr");
	HdrImage i15("ang15.hdr");
	HdrImage i16("ang16.hdr");
	HdrImage i17("ang17.hdr");
	HdrImage i18("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i13);
	imagesToInterpolate.push_back(i15);
	imagesToInterpolate.push_back(i16);
	imagesToInterpolate.push_back(i17);
	imagesToInterpolate.push_back(i18);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(55);
	observations.push_back(85);
	observations.push_back(115);
	observations.push_back(150);
	observations.push_back(185);
	observations.push_back(240);
	observations.push_back(270);
	observations.push_back(300);
	observations.push_back(325);


	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(210);
	finalLi.saveImageAsHdr("ext1linear.hdr");
	std::cout << "ext1linear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(210);
	finalLgi.saveImageAsHdr("ext1lagrange.hdr");
	std::cout << "ext1lagrange:  " << finalLgi.calcDist(base) << std::endl;

	HdrImage one("ang11.hdr");
	HdrImage two("ang13.hdr");
	HdrImage three("ang15.hdr");
	HdrImage four("ang17.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	observations.push_back(180);
	


	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext1forward.hdr");
	std::cout << "ext1forward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext1backward.hdr");
	std::cout << "ext1backward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("ext1stirling.hdr");
	std::cout << "ext1stirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int ext2(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage base("ang13.hdr");

	HdrImage i7("ang7.hdr");
	HdrImage i8("ang8.hdr");
	HdrImage i9("ang9.hdr");
	HdrImage i10("ang10.hdr");
	HdrImage i11("ang11.hdr");
	HdrImage i12("ang12.hdr");
	HdrImage i13("ang13.hdr");
	HdrImage i14("ang14.hdr");
	HdrImage i15("ang15.hdr");
	HdrImage i16("ang16.hdr");
	HdrImage i17("ang17.hdr");
	HdrImage i18("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i14);
	imagesToInterpolate.push_back(i15);
	imagesToInterpolate.push_back(i16);
	imagesToInterpolate.push_back(i17);
	imagesToInterpolate.push_back(i18);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(55);
	observations.push_back(85);
	observations.push_back(115);
	observations.push_back(150);
	observations.push_back(210);
	observations.push_back(240);
	observations.push_back(270);
	observations.push_back(300);
	observations.push_back(325);


	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(185);
	finalLi.saveImageAsHdr("ext2linear.hdr");
	std::cout << "ext2linear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(185);
	finalLgi.saveImageAsHdr("ext2lagrange.hdr");
	std::cout << "ext2lagrange:  " << finalLgi.calcDist(base) << std::endl;

	HdrImage one("ang8.hdr");
	HdrImage two("ang10.hdr");
	HdrImage three("ang12.hdr");
	HdrImage four("ang14.hdr");
	HdrImage five("ang16.hdr");
	HdrImage six("ang18.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	observations.push_back(180);
	observations.push_back(240);
	observations.push_back(300);
	

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(150);
	finalGfi.saveImageAsHdr("ext2forward.hdr");
	std::cout << "ext2forward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(150);
	finalGbi.saveImageAsHdr("ext2backward.hdr");
	std::cout << "ext2backward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(150);
	finalSi.saveImageAsHdr("ext2stirling.hdr");
	std::cout << "ext2stirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int ext3(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage base("ang17.hdr");

	HdrImage i7("ang7.hdr");
	HdrImage i8("ang8.hdr");
	HdrImage i9("ang9.hdr");
	HdrImage i10("ang10.hdr");
	HdrImage i11("ang11.hdr");
	HdrImage i12("ang12.hdr");
	HdrImage i13("ang13.hdr");
	HdrImage i14("ang14.hdr");
	HdrImage i15("ang15.hdr");
	HdrImage i16("ang16.hdr");
	HdrImage i18("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i13);
	imagesToInterpolate.push_back(i14);
	imagesToInterpolate.push_back(i15);
	imagesToInterpolate.push_back(i16);
	imagesToInterpolate.push_back(i18);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(55);
	observations.push_back(85);
	observations.push_back(115);
	observations.push_back(150);
	observations.push_back(185);
	observations.push_back(210);
	observations.push_back(240);
	observations.push_back(270);
	observations.push_back(325);

	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(300);
	finalLi.saveImageAsHdr("ext3linear.hdr");
	std::cout << "ext3linear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(300);
	finalLgi.saveImageAsHdr("ext3lagrange.hdr");
	std::cout << "ext3lagrange:  " << finalLgi.calcDist(base) << std::endl;

	HdrImage one("ang14.hdr");
	HdrImage two("ang16.hdr");
	HdrImage three("ang18.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	

	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("ext3forward.hdr");
	std::cout << "ext3forward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("ext3backward.hdr");
	std::cout << "ext3backward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("ext3stirling.hdr");
	std::cout << "ext3stirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int int1(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage base("iang16.hdr");


	HdrImage i7("iang7.hdr");
	HdrImage i8("iang8.hdr");
	HdrImage i9("iang9.hdr");
	HdrImage i10("iang10.hdr");
	HdrImage i11("iang11.hdr");
	HdrImage i12("iang12.hdr");
	HdrImage i13("iang13.hdr");
	HdrImage i14("iang14.hdr");
	HdrImage i15("iang15.hdr");
	HdrImage i17("iang17.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i13);
	imagesToInterpolate.push_back(i14);
	imagesToInterpolate.push_back(i15);
	imagesToInterpolate.push_back(i17);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(155);
	observations.push_back(185);
	observations.push_back(215);
	observations.push_back(245);
	observations.push_back(305);

	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(275);
	finalLi.saveImageAsHdr("int1linear.hdr");
	std::cout << "int1linear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(275);
	finalLgi.saveImageAsHdr("int1lagrange.hdr");
	std::cout << "int1lagrange:  " << finalLgi.calcDist(base) << std::endl;

	HdrImage one("iang13.hdr");
	HdrImage two("iang15.hdr");
	HdrImage three("iang17.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	


	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("int1forward.hdr");
	std::cout << "int1forward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("int1backward.hdr");
	std::cout << "int1backward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("int1stirling.hdr");
	std::cout << "int1stirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int int2(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage base("iang15.hdr");
		
	HdrImage i7("iang7.hdr");
	HdrImage i8("iang8.hdr");
	HdrImage i9("iang9.hdr");
	HdrImage i10("iang10.hdr");
	HdrImage i11("iang11.hdr");
	HdrImage i12("iang12.hdr");
	HdrImage i13("iang13.hdr");
	HdrImage i14("iang14.hdr");
	HdrImage i16("iang16.hdr");
	HdrImage i17("iang17.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i13);
	imagesToInterpolate.push_back(i14);
	imagesToInterpolate.push_back(i16);
	imagesToInterpolate.push_back(i17);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(155);
	observations.push_back(185);
	observations.push_back(215);
	observations.push_back(275);
	observations.push_back(305);

	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(245);
	finalLi.saveImageAsHdr("int2linear.hdr");
	std::cout << "int2linear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(245);
	finalLgi.saveImageAsHdr("int2lagrange.hdr");
	std::cout << "int2lagrange:  " << finalLgi.calcDist(base) << std::endl;


	HdrImage one("iang12.hdr");
	HdrImage two("iang14.hdr");
	HdrImage three("iang16.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	


	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("int2forward.hdr");
	std::cout << "int2forward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("int2backward.hdr");
	std::cout << "int2backward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("int2stirling.hdr");
	std::cout << "int2stirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}

int focustest(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	
	HdrImage base("ang16.hdr");


	HdrImage i7("ang7.hdr");
	HdrImage i8("ang8.hdr");
	HdrImage i9("ang9.hdr");
	HdrImage i10("ang10.hdr");
	HdrImage i11("ang11.hdr");
	HdrImage i12("ang12.hdr");
	HdrImage i13("ang13.hdr");
	HdrImage i14("ang14.hdr");
	HdrImage i15("ang15.hdr");
	HdrImage i17("ang17.hdr");
	HdrImage i18("ang18.hdr");

	std::vector<HdrImage> imagesToInterpolate;
	imagesToInterpolate.push_back(i7);
	imagesToInterpolate.push_back(i8);
	imagesToInterpolate.push_back(i9);
	imagesToInterpolate.push_back(i10);
	imagesToInterpolate.push_back(i11);
	imagesToInterpolate.push_back(i12);
	imagesToInterpolate.push_back(i13);
	imagesToInterpolate.push_back(i14);
	imagesToInterpolate.push_back(i15);
	imagesToInterpolate.push_back(i17);
	imagesToInterpolate.push_back(i18);

	std::vector<int> observations;
	observations.push_back(0);
	observations.push_back(30);
	observations.push_back(55);
	observations.push_back(85);
	observations.push_back(115);
	observations.push_back(150);
	observations.push_back(185);
	observations.push_back(210);
	observations.push_back(240);
	observations.push_back(300);
	observations.push_back(325);

	LinearInterpolator li(observations, imagesToInterpolate, 30);
	HdrImage finalLi = li.calculateInterpolationOn(270);
	finalLi.saveImageAsHdr("focuslinear.hdr");
	std::cout << "focuslinear:  " << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator lgi(observations, imagesToInterpolate, 30);
	HdrImage finalLgi = lgi.calculateInterpolationOn(270);
	finalLgi.saveImageAsHdr("focuslagrange.hdr");
	std::cout << "focuslagrange:  " << finalLgi.calcDist(base) << std::endl;

	HdrImage one("ang13.hdr");
	HdrImage two("ang15.hdr");
	HdrImage three("ang17.hdr");

	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);

	observations.clear();
	observations.push_back(0);
	observations.push_back(60);
	observations.push_back(120);
	


	GaussianForwardInterpolator gfi(observations, imagesToInterpolate, 60);
	HdrImage finalGfi = gfi.calculateInterpolationOn(90);
	finalGfi.saveImageAsHdr("focusforward.hdr");
	std::cout << "focusforward:  " << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate, 60);
	HdrImage finalGbi = gbi.calculateInterpolationOn(90);
	finalGbi.saveImageAsHdr("focusbackward.hdr");
	std::cout << "focusbackward:  " << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate, 60);
	HdrImage finalSi = si.calculateInterpolationOn(90);
	finalSi.saveImageAsHdr("focusstirling.hdr");
	std::cout << "focusstirling:  " << finalSi.calcDist(base) << std::endl;

	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}
