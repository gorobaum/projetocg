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

int main(int argc, char** argv) {
	/*
	if (argc < 2) {
		std::cout << "Precisa passar o nome dos arquivos coração! \n";    
		return 0;
	}
	vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_params.push_back(95);
	Mat staticImage = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    Mat result = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    std::string fileName;
    char* extension = std::strrchr(argv[1], '.');
    fileName = argv[2];
    fileName += "symmetric";
    fileName += extension;
    // imwrite(fileName.c_str(), result, compression_params);
	*/
	openhdr("imagem1.hdr");
	return 0;

}