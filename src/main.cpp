#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include <FreeImage.h>

#include "gaussinterpolator.h"
#include "hdrimage.h"

int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));

	std::cout << FreeImage_GetVersion() << "\n";
	HdrImage teste("lpbom.hdr");
	std::cout << "Color in [0,0] = " << teste.getPixelAt(0,0).red << "\n";
	

	FIBITMAP *bitmap = FreeImage_AllocateT(FIT_RGBAF, 320, 240);
	if (bitmap) 
	{
		FreeImage_Unload(bitmap);
	}
	FIBITMAP *bitmap2 = FreeImage_Load(FIF_PNG, "menuNew.png", PNG_DEFAULT);
	if(bitmap2)
	{
		if (FreeImage_Save(FIF_BMP, bitmap2, "menuNew.bmp", BMP_DEFAULT)) 
		{
			// bitmap successfully saved!
		}
		FreeImage_Unload(bitmap2);
	}
	FIBITMAP *bitmap3 = FreeImage_Load(FIF_HDR, "lpbom.hdr", HDR_DEFAULT);
	if(bitmap3)
	{
		if (FreeImage_Save(FIF_PNG, FreeImage_ToneMapping(bitmap3, FITMO_FATTAL02), "lpbom.png", PNG_DEFAULT));
		{
			// bitmap successfully saved!
		}
		FreeImage_Unload(bitmap3);
	}
	//std::cout << "Has pixeis " << FreeImage_GetHeight(bitmap) << "\n";

	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}