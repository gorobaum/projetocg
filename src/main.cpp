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
	
	DLL_API void DLL_CALLCONV FreeImage_DeInitialise();
	return 0;
}