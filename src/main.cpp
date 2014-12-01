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

int main(int argc, char** argv) 
{
	ext1(argc,argv);
	ext2(argc,argv);
	ext3(argc,argv);
	int1(argc,argv);
	int2(argc,argv);
	focustest(argc,argv);
	return 0;
}