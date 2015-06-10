#ifndef PROJCG_HDRIMAGE_H_
#define PROJCG_HDRIMAGE_H_

#include <string>
#include <memory>
#include <iostream>

#include <FreeImage.h>


class HdrImage {
public:
	HdrImage(int width, int height) {
		imageBitmap_ = std::shared_ptr<FIBITMAP>(FreeImage_AllocateT(FIT_RGBF, width, height, 96), &FreeImage_Unload);
	}
	HdrImage(std::string filename) {
		imageBitmap_ = std::shared_ptr<FIBITMAP>(FreeImage_Load(FIF_HDR, filename.c_str(), HDR_DEFAULT), &FreeImage_Unload);
		//int bytespp = FreeImage_GetLine(imageBitmap_.get()) / FreeImage_GetWidth(imageBitmap_.get()); 
		// CARREGA 12 BYTES POR PIXEL - FORMATO FLOAT COM 96 BITS POR PIXEL -- RGBE APENAS PARA SALVAR O ARQUIVO - TRABALHA NA PRATICA COMO FLOAT
	}
	HdrImage(const std::shared_ptr<FIBITMAP> &imageBitmap) :
		imageBitmap_(imageBitmap) {}
	int getWidth();
	int getHeight();
	void saveImageAsPng(std::string filename);
	void saveImageAsHdr(std::string filename);
	FIRGBF getPixelAt(unsigned int x, unsigned int y);
	float calcDist(const HdrImage& param);
	HdrImage diffAbs(const HdrImage& param);
	float hdrabs();
	HdrImage operator-(const HdrImage& param);
	HdrImage operator+(const HdrImage& param);
	HdrImage operator*(const double& param);
	HdrImage operator/(const double& param);
	HdrImage clamp();


private:
	std::shared_ptr<FIBITMAP> imageBitmap_;
};

#endif