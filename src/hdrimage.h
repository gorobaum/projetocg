#ifndef PROJCG_HDRIMAGE_H_
#define PROJCG_HDRIMAGE_H_

#include <string>
#include <FreeImage.h>

class HdrImage {
public:
	HdrImage(int width, int height) {
		imageBitmap_ = FreeImage_AllocateT(FIT_RGBAF, width, height, 128, 0, 0, 0);
	}
	HdrImage(std::string filename) {
		imageBitmap_ = FreeImage_Load(FIF_HDR, filename.c_str(), HDR_DEFAULT);
	}
	HdrImage(FIBITMAP *imageBitmap) :
		imageBitmap_(imageBitmap) {}
	int getWidth();
	int getHeight();
	void saveImageAsPng(std::string filename);
	void saveImageAsHdr(std::string filename);
	FIRGBF getPixelAt(unsigned int x, unsigned int y);
	HdrImage operator-(const HdrImage& param);
	HdrImage operator+(const HdrImage& param);
	HdrImage operator*(const double& param);
	HdrImage operator/(const double& param);
	HdrImage HdrImage::clamp();

private:
	FIBITMAP *imageBitmap_;
};

#endif