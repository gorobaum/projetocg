#include <string>
#include <iostream>
#include <vector>
#include <cstring>

#include "FreeImage.h"

int main(int argc, char** argv) 
{
	FreeImage_Initialise();
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