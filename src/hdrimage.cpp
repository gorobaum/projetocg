#include <stdlib.h>
#include <omp.h>

#include "hdrimage.h"
#include "minmax.h"



HdrImage HdrImage::operator-(const HdrImage& param) {
	int height = static_cast<int>(FreeImage_GetHeight(imageBitmap_.get()));
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *paramBits = (FIRGBF *)FreeImage_GetScanLine(param.imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = thisBits[x].red - paramBits[x].red;
			diffImageBits[x].blue = thisBits[x].blue - paramBits[x].blue;
			diffImageBits[x].green = thisBits[x].green - paramBits[x].green;
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

HdrImage HdrImage::operator+(const HdrImage& param) {
	int height = FreeImage_GetHeight(imageBitmap_.get());
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *paramBits = (FIRGBF *)FreeImage_GetScanLine(param.imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = thisBits[x].red + paramBits[x].red;
			diffImageBits[x].blue = thisBits[x].blue + paramBits[x].blue;
			diffImageBits[x].green = thisBits[x].green + paramBits[x].green;
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

HdrImage HdrImage::operator*(const double& param) {
	int height = FreeImage_GetHeight(imageBitmap_.get());
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = thisBits[x].red * param;
			diffImageBits[x].blue = thisBits[x].blue * param;
			diffImageBits[x].green = thisBits[x].green * param;
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

HdrImage HdrImage::operator/(const double& param) {
	int height = FreeImage_GetHeight(imageBitmap_.get());
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = thisBits[x].red / param;
			diffImageBits[x].blue = thisBits[x].blue / param;
			diffImageBits[x].green = thisBits[x].green / param;
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

float HdrImage::calcDist(const HdrImage& param) {
	HdrImage diffImage = diffAbs(param);
	float dist = 0.0;
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_.get()); y++) {
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage.imageBitmap_.get(), y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_.get()); x++)
			dist += diffImageBits[x].red + diffImageBits[x].green + diffImageBits[x].blue;
	}
	return dist;
}

HdrImage HdrImage::diffAbs(const HdrImage& param) {
	int height = FreeImage_GetHeight(imageBitmap_.get());
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *paramBits = (FIRGBF *)FreeImage_GetScanLine(param.imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = abs(thisBits[x].red - paramBits[x].red);
			diffImageBits[x].blue = abs(thisBits[x].blue - paramBits[x].blue);
			diffImageBits[x].green = abs(thisBits[x].green - paramBits[x].green);
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

float HdrImage::hdrabs() {
	float dist = 0.0;
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_.get()); y++) {
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_.get()); x++)
			dist += diffImageBits[x].red + diffImageBits[x].green + diffImageBits[x].blue;
	}
	return dist;
}


HdrImage HdrImage::clamp() {
	int height = FreeImage_GetHeight(imageBitmap_.get());
	int width = FreeImage_GetWidth(imageBitmap_.get());
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 96);
	#pragma omp parallel for
	for (int y = 0; y < height; y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (int x = 0; x < width; x++) {
			diffImageBits[x].red = max(thisBits[x].red, 0.0);
			diffImageBits[x].blue = max(thisBits[x].blue, 0.0);
			diffImageBits[x].green = max(thisBits[x].green, 0.0);
		}
	}
	std::shared_ptr<FIBITMAP> macaco(diffImage, FreeImage_Unload);
	HdrImage ret(macaco);
	return ret;
}

int HdrImage::getWidth() {
	return FreeImage_GetWidth(imageBitmap_.get());
}

int HdrImage::getHeight() {
	return FreeImage_GetHeight(imageBitmap_.get());
}	

void HdrImage::saveImageAsPng(std::string filename) {
	FreeImage_Save(FIF_PNG, FreeImage_ToneMapping(imageBitmap_.get(), FITMO_REINHARD05), filename.c_str(), PNG_DEFAULT);
}


void HdrImage::saveImageAsHdr(std::string filename) {
	FreeImage_Save(FIF_HDR, imageBitmap_.get(), filename.c_str(), HDR_DEFAULT);
}


FIRGBF HdrImage::getPixelAt(unsigned int x, unsigned int y) {
	FIRGBF ret;
	y = FreeImage_GetHeight(imageBitmap_.get())-y-1;
	if (y < FreeImage_GetHeight(imageBitmap_.get()) && y >= 0) 
		if (x < FreeImage_GetWidth(imageBitmap_.get()) && x >= 0) {
			FIRGBF *bits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
			ret = bits[x];
		}
	return ret;
}

void HdrImage::setPixelAt(unsigned int x, unsigned int y, FIRGBF rgb)
{
	y = FreeImage_GetHeight(imageBitmap_.get())-y-1;
	if (y < FreeImage_GetHeight(imageBitmap_.get()) && y >= 0) 
		if (x < FreeImage_GetWidth(imageBitmap_.get()) && x >= 0) {
			FIRGBF *bits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_.get(), y);
			bits[x].blue = rgb.blue;
			bits[x].red = rgb.red;
			bits[x].green = rgb.green;
		}
	return;
}