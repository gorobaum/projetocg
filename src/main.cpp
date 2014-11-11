#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "interpolation.h"
#include "imagefunctions.h"

using namespace cv;

#include "hdrfunctions.h"
#include "FreeImage.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	std::cout << FreeImage_GetVersion();
	FIBITMAP *bitmap = FreeImage_AllocateT(FIT_RGBAF, 320, 240);
	if (bitmap) 
	{
	// bitmap successfully created!
		
	FreeImage_Unload(bitmap);
	}
	FIBITMAP *bitmap2 = FreeImage_Load(FIF_PNG, "menuNew.png", PNG_DEFAULT);
	if(bitmap2)
	{
		FreeImage_Unload(bitmap2);
	}
	FIBITMAP *bitmap3 = FreeImage_Load(FIF_HDR, "lpbom.hdr", HDR_DEFAULT);
	if(bitmap3)
	{
		FreeImage_Unload(bitmap3);
	}
	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}