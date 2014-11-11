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
	FIBITMAP *bitmap = FreeImage_AllocateT(FIT_RGBAF, 320, 240, 32);
	if (bitmap) 
	{
	// bitmap successfully created!
	FreeImage_Unload(bitmap);
	}
	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}