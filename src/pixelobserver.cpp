#include "pixelobserver.h"

void PixelObserver::addNewObservation(HdrImage image, int obTime) {
	observations.push_back(image.getPixelAt(x_,y_));
	observationTime.push_back(obTime);
}

void PixelObserver::printObservationsForPlot(std::string filename) {
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out);
	for(unsigned int i = 0; i < observations.size(); i++)
		ofs << observationTime[i] << " " << observations[i].red << " " << observations[i].green << " " << observations[i].blue << "\n";
}