#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <FreeImage.h>

#include "gaussinterpolator.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
	std::cout << FreeImage_GetVersion() << "\n";
	FIBITMAP *bitmap = FreeImage_AllocateT(FIT_RGBAF, 320, 240);
	if (bitmap) 
	{
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
		RGBQUAD value;
		FreeImage_GetPixelColor(bitmap3, 0, 0, &value);
		std::cout << "Color in [0,0] = " << value.rgbRed << "\n";
		FreeImage_Unload(bitmap3);
	}
	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}