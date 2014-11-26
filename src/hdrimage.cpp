#include "hdrimage.h"
#include "minmax.h"


HdrImage HdrImage::operator-(const HdrImage& param) {
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 128, 0, 0, 0);
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_); y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
		FIRGBF *paramBits = (FIRGBF *)FreeImage_GetScanLine(param.imageBitmap_, y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_); x++) {
			diffImageBits[x].red = thisBits[x].red - paramBits[x].red;
			diffImageBits[x].blue = thisBits[x].blue - paramBits[x].blue;
			diffImageBits[x].green = thisBits[x].green - paramBits[x].green;
		}
	}
	HdrImage ret(diffImage);
	return ret;
}

HdrImage HdrImage::operator+(const HdrImage& param) {
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 128, 0, 0, 0);
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_); y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
		FIRGBF *paramBits = (FIRGBF *)FreeImage_GetScanLine(param.imageBitmap_, y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_); x++) {
			diffImageBits[x].red = thisBits[x].red + paramBits[x].red;
			diffImageBits[x].blue = thisBits[x].blue + paramBits[x].blue;
			diffImageBits[x].green = thisBits[x].green + paramBits[x].green;
		}
	}
	HdrImage ret(diffImage);
	return ret;
}

HdrImage HdrImage::operator*(const double& param) {
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 128, 0, 0, 0);
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_); y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_); x++) {
			diffImageBits[x].red = thisBits[x].red * param;
			diffImageBits[x].blue = thisBits[x].blue * param;
			diffImageBits[x].green = thisBits[x].green * param;
		}
	}
	HdrImage ret(diffImage);
	return ret;
}

HdrImage HdrImage::operator/(const double& param) {
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 128, 0, 0, 0);
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_); y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_); x++) {
			diffImageBits[x].red = thisBits[x].red / param;
			diffImageBits[x].blue = thisBits[x].blue / param;
			diffImageBits[x].green = thisBits[x].green / param;
		}
	}
	HdrImage ret(diffImage);
	return ret;
}

HdrImage HdrImage::clamp() {
	FIBITMAP * diffImage = FreeImage_AllocateT(FIT_RGBF, getWidth(), getHeight(), 128, 0, 0, 0);
	for (unsigned int y = 0; y < FreeImage_GetHeight(imageBitmap_); y++) {
		FIRGBF *thisBits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
		FIRGBF *diffImageBits = (FIRGBF *)FreeImage_GetScanLine(diffImage, y);
		for (unsigned int x = 0; x < FreeImage_GetWidth(imageBitmap_); x++) {
			diffImageBits[x].red = max(thisBits[x].red, 0.0);
			diffImageBits[x].blue = max(thisBits[x].blue, 0.0);
			diffImageBits[x].green = max(thisBits[x].green, 0.0);
		}
	}
	HdrImage ret(diffImage);
	return ret;
}

int HdrImage::getWidth() {
	return FreeImage_GetWidth(imageBitmap_);
}

int HdrImage::getHeight() {
	return FreeImage_GetHeight(imageBitmap_);
}	

void HdrImage::saveImageAsPng(std::string filename) {
	FreeImage_Save(FIF_PNG, FreeImage_ToneMapping(imageBitmap_, FITMO_FATTAL02), filename.c_str(), PNG_DEFAULT);
}

void HdrImage::saveImageAsHdr(std::string filename) {
	FreeImage_Save(FIF_HDR, imageBitmap_, filename.c_str(), HDR_DEFAULT);
}


FIRGBF HdrImage::getPixelAt(unsigned int x, unsigned int y) {
	FIRGBF ret;
	if (y < FreeImage_GetHeight(imageBitmap_)) 
		if (x < FreeImage_GetWidth(imageBitmap_)) {
			FIRGBF *bits = (FIRGBF *)FreeImage_GetScanLine(imageBitmap_, y);
			ret = bits[x];
		}
	return ret;
}