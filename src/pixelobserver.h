#ifndef PROJCG_PIXELOBSERVER_H_
#define PROJCG_PIXELOBSERVER_H_

#include <string>
#include <FreeImage.h>
#include <fstream>
#include <vector>

#include "hdrimage.h"

class PixelObserver {
public:
	PixelObserver(int x, int y):
		x_(x),
		y_(y) {}
	void addNewObservation(HdrImage image, int obTime);
	void printObservationsForPlot(std::string filename);
private:
	int x_;
	int y_;
	std::vector<FIRGBF> observations;
	std::vector<int> observationTime;
};

#endif