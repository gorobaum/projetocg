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
	std::cout << std::endl;
	std::cout << std::endl;
	ext2(argc,argv);
	std::cout << std::endl;
	std::cout << std::endl;
	ext3(argc,argv);
	std::cout << std::endl;
	std::cout << std::endl;
	int1(argc,argv);
	std::cout << std::endl;
	std::cout << std::endl;
	int2(argc,argv);
	std::cout << std::endl;
	std::cout << std::endl;
	focustest(argc,argv);
	return 0;
}