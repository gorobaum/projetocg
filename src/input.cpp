#include <fstream>
#include <iostream>
#include <string>

#include "input.h"

using namespace std;


void interpolationsTypesVerifier(char *type, bool &lagrange, bool &linear, bool &quadratic, bool &gaussforward, bool &gaussbackward, bool &stirling)
{
	if(strcmp(type, "lagrange")==0) lagrange = true;
	else if(strcmp(type, "linear")==0) linear = true;
	else if(strcmp(type, "quadratic")==0) quadratic = true;
	else if(strcmp(type, "gaussforward")==0) gaussforward = true;
	else if(strcmp(type, "gaussbackward")==0) gaussbackward = true;
	else if(strcmp(type, "stirling")==0) stirling = true;
	else cout << "Undefined interpolation.\n";
}


void fileRead(char *fname)
{
	int interpolationTypes;
	int observationTime;
	char imageFile[20];
	char interpolationType[20];
	bool lagrange,linear,quadratic,gaussforward,gaussbackward,stirling;
	int imageTime;
	vector<HdrImage> images;
	vector<int> observations;

	string line;
	fstream file;
	int i = 0;
	lagrange=linear=quadratic=gaussforward=gaussbackward=stirling=false;

	file.open(fname, fstream::in);
	if (!file.is_open())
	{
		cout << "Error opening file: " << fname << "\n";
	}

	getline(file,line);
	sscanf(line.c_str(), "%d %d", &interpolationTypes, &observationTime);
	while (getline(file,line))
    {
		if(i < interpolationTypes)
		{
			sscanf(line.c_str(), "%s", interpolationType);
			interpolationsTypesVerifier(interpolationType, lagrange, linear, quadratic, gaussforward, gaussbackward, stirling);
			i++;
		}
		else
		{
			sscanf(line.c_str(), "%s %d", imageFile, &imageTime );
			images.push_back(HdrImage(imageFile));
			observations.push_back(imageTime);
		}
    }
	file.close();

	return;
}