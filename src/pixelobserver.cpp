#include "pixelobserver.h"

void PixelObserver::addNewObservation(HdrImage image) {
	observations.push_back(image.getPixelAt(x_,y_));
}

void PixelObserver::printObservationsForPlot(std::string filename) {
	std::ofstream ofs;
		ofs.open(filename, std::ofstream::out);
		ofs << x_ << " " << y_ << "\n";
		for(std::vector<FIRGBF>::iterator it=observations.begin(); it != observations.end(); ++it)
			ofs << (*it).red << " " << (*it).green << " " << (*it).blue << "\n";
}