#include <fstream>
#include <iostream>
#include <string>

#include "input.h"

using namespace std;


void interpolationsTypesVerifier(char *type, bool &lagrange, bool &linear, bool &quadratic, bool &gaussforward, bool &gaussbackward, bool &stirling, bool &ncspline, bool &bezier, bool &bezierquad, bool &beziercub, bool &bsplinecub)
{
	if(strcmp(type, "lagrange")==0) lagrange = true;
	else if(strcmp(type, "linear")==0) linear = true;
	else if(strcmp(type, "quadratic")==0) quadratic = true;
	else if(strcmp(type, "gaussforward")==0) gaussforward = true;
	else if(strcmp(type, "gaussbackward")==0) gaussbackward = true;
	else if(strcmp(type, "stirling")==0) stirling = true;
	else if(strcmp(type, "ncspline")==0) ncspline = true;
	else if(strcmp(type, "bezier")==0) bezier = true;
	else if(strcmp(type, "bezierquad")==0) bezierquad = true;
	else if(strcmp(type, "beziercub")==0) beziercub = true;
	else if(strcmp(type, "bsplinecub")==0) bsplinecub = true;
	else cout << "Undefined interpolation.\n";
}

void interpolate(char *seriesName, vector<HdrImage> images, vector<int> observations, int observationTime, bool &lagrange, bool &linear, bool &quadratic, bool &gaussforward, bool &gaussbackward, bool &stirling, bool &ncspline, bool &bezier, bool &bezierquad, bool &beziercub, bool &bsplinecub)
{
	string sfname;
	if(lagrange) 
	{
		sfname.erase();
		LaGrangeInterpolator la(observations, images);
		sfname.append(seriesName).append("\\lagrange").append(to_string(observationTime)).append(".hdr");
		la.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);
	}
	if(linear)
	{
		sfname.erase();
		LinearInterpolator li(observations, images);
		sfname.append(seriesName).append("\\linear").append(to_string(observationTime)).append(".hdr");
		li.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(quadratic)
	{
		sfname.erase();
		QuadraticInterpolator qua(observations, images);
		sfname.append(seriesName).append("\\quadratic").append(to_string(observationTime)).append(".hdr");
		qua.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(gaussforward)
	{
		sfname.erase();
		GaussianForwardInterpolator gaf(observations, images);
		sfname.append(seriesName).append("\\gaussforward").append(to_string(observationTime)).append(".hdr");
		gaf.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(gaussbackward)
	{
		sfname.erase();
		GaussianBackwardInterpolator gab(observations, images);
		sfname.append(seriesName).append("\\gaussbackward").append(to_string(observationTime)).append(".hdr");
		gab.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(stirling)
	{
		sfname.erase();
		StirlingInterpolator stir(observations, images);
		sfname.append(seriesName).append("\\stirling").append(to_string(observationTime)).append(".hdr");
		stir.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(ncspline)
	{
		sfname.erase();
		NaturalCubicSplineInterpolator ncs(observations, images);
		sfname.append(seriesName).append("\\ncspline").append(to_string(observationTime)).append(".hdr");
		ncs.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(bezier)
	{
		sfname.erase();
		BezierApproximator bez(observations, images);
		sfname.append(seriesName).append("\\bezier").append(to_string(observationTime)).append(".hdr");
		bez.calculateContinuousInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(bezierquad)
	{
		sfname.erase();
		BezierQuadraticApproximator bezq(observations, images);
		sfname.append(seriesName).append("\\bezierquad").append(to_string(observationTime)).append(".hdr");
		bezq.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(beziercub)
	{
		sfname.erase();
		BezierCubicApproximator bezc(observations, images);
		sfname.append(seriesName).append("\\beziercub").append(to_string(observationTime)).append(".hdr");
		bezc.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
	if(bsplinecub)
	{
		sfname.erase();
		BSplineApproximator bsc(observations, images);
		sfname.append(seriesName).append("\\bsplinecub").append(to_string(observationTime)).append(".hdr");
		bsc.calculateInterpolationOn(observationTime).saveImageAsHdr(sfname);;
	}
}

void compare(char *seriesName, char *imageFile, char *imageFile2, char *description)
{
	string sfname;
	sfname.erase();
	sfname.append(seriesName).append("\\dif_").append(description).append(".hdr");
	HdrImage im1(imageFile);
	HdrImage im2(imageFile2);
	HdrImage dif = im1.diffAbs(im2);
	cout << "Dif - " << description << ": " << dif.hdrabs() << endl;
	dif.saveImageAsHdr(sfname);
}


void fileRead(char *fname)
{
	int interpolationTypes;
	int observationTime;
	char inputType[40];
	char seriesName[40];
	char imageFile[40];
	char imageFile2[40];
	char description[40];
	char interpolationType[40];
	bool lagrange,linear,quadratic,gaussforward,gaussbackward,stirling,ncspline,bezier,bezierquad,beziercub,bsplinecub;
	int imageTime;
	vector<HdrImage> images;
	vector<int> observations;

	string line;
	fstream file;
	int i = 0;
	lagrange=linear=quadratic=gaussforward=gaussbackward=stirling=ncspline=bezier=bezierquad=beziercub=bsplinecub=false;

	file.open(fname, fstream::in);
	if (!file.is_open())
	{
		cout << "Error opening file: " << fname << "\n";
	}


	getline(file,line);
	sscanf(line.c_str(), "%s %s", inputType, seriesName);

	if((strcmp(inputType, "interpolate") == 0) || strcmp(inputType, "interpolate_continuos") == 0)
	{
		getline(file,line);
		sscanf(line.c_str(), "%d %d", &interpolationTypes, &observationTime);
		while (getline(file,line))
		{
			if(i < interpolationTypes)
			{
				sscanf(line.c_str(), "%s", interpolationType);
				interpolationsTypesVerifier(interpolationType, lagrange, linear, quadratic, gaussforward, gaussbackward, stirling, ncspline, bezier, bezierquad, beziercub, bsplinecub);
				i++;
			}
			else
			{
				sscanf(line.c_str(), "%s %d", imageFile, &imageTime );
				images.push_back(HdrImage(imageFile));
				observations.push_back(imageTime);
			}
		}
		if(strcmp(inputType, "interpolate") == 0)
		{
			interpolate(seriesName, images, observations, observationTime, lagrange, linear, quadratic, gaussforward, gaussbackward, stirling,ncspline, bezier, bezierquad, beziercub, bsplinecub);
		}
		else
		{
			int timeDiff = observationTime;
			for(observationTime = observations[0]; observationTime <= observations[observations.size()-1]; observationTime = observationTime+timeDiff)
			{
				interpolate(seriesName, images, observations, observationTime, lagrange, linear, quadratic, gaussforward, gaussbackward, stirling,ncspline, bezier, bezierquad, beziercub, bsplinecub);
			}
		}
	}
	else if(strcmp(inputType, "compare") == 0)
	{
		while (getline(file,line))
		{
			sscanf(line.c_str(), "%s %s %s", imageFile, imageFile2, description );
			compare(seriesName, imageFile, imageFile2, description);
		}
	}
	file.close();
	return;
}