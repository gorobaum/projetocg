#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

#include <FreeImage.h>

#include "linearinterpolator.h"
#include "lagrangeinterpolator.h"
#include "gaussianforwardinterpolator.h"
#include "gaussianbackwardinterpolator.h"
#include "stirlinginterpolator.h"
#include "hdrimage.h"
#include "pixelobserver.h"

#include "input.h"

void internalImages1()
{
	
	HdrImage base("iang16.hdr");

	HdrImage one("iang1.hdr");
	HdrImage two("iang2.hdr");
	HdrImage three("iang3.hdr");
	HdrImage four("iang4.hdr");
	HdrImage five("iang5.hdr");
	HdrImage six("iang6.hdr");
	HdrImage seven("iang7.hdr");
	HdrImage eight("iang8.hdr");
	HdrImage nine("iang9.hdr");
	HdrImage ten("iang10.hdr");
	HdrImage eleven("iang11.hdr");
	HdrImage twelve("iang12.hdr");
	HdrImage thirteen("iang13.hdr");
	HdrImage fourteen("iang14.hdr");
	HdrImage fifteen("iang15.hdr");
	HdrImage sixteen("iang16.hdr");
	HdrImage seventeen("iang17.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	/*imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);
	imagesToInterpolate.push_back(seven);*/
	imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	//imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);


	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(150);
	observations.push_back(180);
	observations.push_back(210);
	observations.push_back(240);
	//observations.push_back(270);
	observations.push_back(300);

	LinearInterpolator li(observations, imagesToInterpolate);
	HdrImage finalLi = li.calculateInterpolationOn(270);
	finalLi.saveImageAsHdr("correto/linear_int1.hdr");
	finalLi.diffAbs(base).saveImageAsHdr("correto/linear_dif_int1.hdr");
	std::cout << "Linar: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator la(observations, imagesToInterpolate);
	HdrImage finalLa = la.calculateInterpolationOn(270);
	finalLa.saveImageAsHdr("correto/lagrange_int1.hdr");
	finalLa.diffAbs(base).saveImageAsHdr("correto/lagrange_dif_int1.hdr");
	std::cout << "Lagrange: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLa.calcDist(base) << std::endl;




	imagesToInterpolate.clear();
	//imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	//imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	//imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	//imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	//imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);



	observations.clear();
	//observations.push_back(30);
	observations.push_back(60);
	//observations.push_back(90);
	observations.push_back(120);
	//observations.push_back(150);
	observations.push_back(180);
	//observations.push_back(210);
	observations.push_back(240);
	//observations.push_back(270);
	observations.push_back(300);

	
	GaussianForwardInterpolator gfi(observations, imagesToInterpolate);
	HdrImage finalGfi = gfi.calculateInterpolationOn(270);
	finalGfi.saveImageAsHdr("correto/forward_int1.hdr");
	finalGfi.diffAbs(base).saveImageAsHdr("correto/forward_dif_int1.hdr");
	std::cout << "Forward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate);
	HdrImage finalGbi = gbi.calculateInterpolationOn(270);
	finalGbi.saveImageAsHdr("correto/backward_int1.hdr");
	finalGbi.diffAbs(base).saveImageAsHdr("correto/backward_dif_int1.hdr");
	std::cout << "Backward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate);
	HdrImage finalSi = si.calculateInterpolationOn(270);
	finalSi.saveImageAsHdr("correto/stirling_int1.hdr");
	finalSi.diffAbs(base).saveImageAsHdr("correto/stirling_dif_int1.hdr");
	std::cout << "Stirling: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalSi.calcDist(base) << std::endl;

}

void internalImages2()
{
	
	HdrImage base("iang15.hdr");

	HdrImage one("iang1.hdr");
	HdrImage two("iang2.hdr");
	HdrImage three("iang3.hdr");
	HdrImage four("iang4.hdr");
	HdrImage five("iang5.hdr");
	HdrImage six("iang6.hdr");
	HdrImage seven("iang7.hdr");
	HdrImage eight("iang8.hdr");
	HdrImage nine("iang9.hdr");
	HdrImage ten("iang10.hdr");
	HdrImage eleven("iang11.hdr");
	HdrImage twelve("iang12.hdr");
	HdrImage thirteen("iang13.hdr");
	HdrImage fourteen("iang14.hdr");
	HdrImage fifteen("iang15.hdr");
	HdrImage sixteen("iang16.hdr");
	HdrImage seventeen("iang17.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	/*imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);
	imagesToInterpolate.push_back(seven);*/
	imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	//imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);


	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(150);
	observations.push_back(180);
	observations.push_back(210);
	//observations.push_back(240);
	observations.push_back(270);
	observations.push_back(300);

	LinearInterpolator li(observations, imagesToInterpolate);
	HdrImage finalLi = li.calculateInterpolationOn(240);
	finalLi.saveImageAsHdr("correto/linear_int2.hdr");
	finalLi.diffAbs(base).saveImageAsHdr("correto/linear_dif_int2.hdr");
	std::cout << "Linar: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator la(observations, imagesToInterpolate);
	HdrImage finalLa = la.calculateInterpolationOn(240);
	finalLa.saveImageAsHdr("correto/lagrange_int2.hdr");
	finalLa.diffAbs(base).saveImageAsHdr("correto/lagrange_dif_int2.hdr");
	std::cout << "Lagrange: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLa.calcDist(base) << std::endl;




	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(eight);
	//imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	//imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	//imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	//imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	//imagesToInterpolate.push_back(seventeen);



	observations.clear();
	observations.push_back(30);
	//observations.push_back(60);
	observations.push_back(90);
	//observations.push_back(120);
	observations.push_back(150);
	//observations.push_back(180);
	observations.push_back(210);
	//observations.push_back(240);
	observations.push_back(270);
	//observations.push_back(300);

	
	GaussianForwardInterpolator gfi(observations, imagesToInterpolate);
	HdrImage finalGfi = gfi.calculateInterpolationOn(240);
	finalGfi.saveImageAsHdr("correto/forward_int2.hdr");
	finalGfi.diffAbs(base).saveImageAsHdr("correto/forward_dif_int2.hdr");
	std::cout << "Forward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate);
	HdrImage finalGbi = gbi.calculateInterpolationOn(240);
	finalGbi.saveImageAsHdr("correto/backward_int2.hdr");
	finalGbi.diffAbs(base).saveImageAsHdr("correto/backward_dif_int2.hdr");
	std::cout << "Backward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate);
	HdrImage finalSi = si.calculateInterpolationOn(240);
	finalSi.saveImageAsHdr("correto/stirling_int2.hdr");
	finalSi.diffAbs(base).saveImageAsHdr("correto/stirling_dif_int2.hdr");
	std::cout << "Stirling: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalSi.calcDist(base) << std::endl;

}

void externalImages1()
{
	
	HdrImage base("ang14.hdr");

	HdrImage one("ang1.hdr");
	HdrImage two("ang2.hdr");
	HdrImage three("ang3.hdr");
	HdrImage four("ang4.hdr");
	HdrImage five("ang5.hdr");
	HdrImage six("ang6.hdr");
	HdrImage seven("ang7.hdr");
	HdrImage eight("ang8.hdr");
	HdrImage nine("ang9.hdr");
	HdrImage ten("ang10.hdr");
	HdrImage eleven("ang11.hdr");
	HdrImage twelve("ang12.hdr");
	HdrImage thirteen("ang13.hdr");
	HdrImage fourteen("ang14.hdr");
	HdrImage fifteen("ang15.hdr");
	HdrImage sixteen("ang16.hdr");
	HdrImage seventeen("ang17.hdr");
	HdrImage eighteen("ang18.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	/*imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);
	imagesToInterpolate.push_back(seven);*/
	imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	//imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);
	imagesToInterpolate.push_back(eighteen);


	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(150);
	observations.push_back(180);
	//observations.push_back(210);
	observations.push_back(240);
	observations.push_back(270);
	observations.push_back(300);
	observations.push_back(330);

	LinearInterpolator li(observations, imagesToInterpolate);
	HdrImage finalLi = li.calculateInterpolationOn(210);
	finalLi.saveImageAsHdr("correto/linear_ext1.hdr");
	finalLi.diffAbs(base).saveImageAsHdr("correto/linear_dif_ext1.hdr");
	std::cout << "Linar: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator la(observations, imagesToInterpolate);
	HdrImage finalLa = la.calculateInterpolationOn(210);
	finalLa.saveImageAsHdr("correto/lagrange_ext1.hdr");
	finalLa.diffAbs(base).saveImageAsHdr("correto/lagrange_dif_ext1.hdr");
	std::cout << "Lagrange: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLa.calcDist(base) << std::endl;




	imagesToInterpolate.clear();
	//imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	//imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	//imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	//imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	//imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);
	//imagesToInterpolate.push_back(eighteen);



	observations.clear();
	//observations.push_back(30);
	observations.push_back(60);
	//observations.push_back(90);
	observations.push_back(120);
	//observations.push_back(150);
	observations.push_back(180);
	//observations.push_back(210);
	observations.push_back(240);
	//observations.push_back(270);
	observations.push_back(300);
	//observations.push_back(330);

	
	GaussianForwardInterpolator gfi(observations, imagesToInterpolate);
	HdrImage finalGfi = gfi.calculateInterpolationOn(210);
	finalGfi.saveImageAsHdr("correto/forward_ext1.hdr");
	finalGfi.diffAbs(base).saveImageAsHdr("correto/forward_dif_ext1.hdr");
	std::cout << "Forward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate);
	HdrImage finalGbi = gbi.calculateInterpolationOn(210);
	finalGbi.saveImageAsHdr("correto/backward_ext1.hdr");
	finalGbi.diffAbs(base).saveImageAsHdr("correto/backward_dif_ext1.hdr");
	std::cout << "Backward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate);
	HdrImage finalSi = si.calculateInterpolationOn(210);
	finalSi.saveImageAsHdr("correto/stirling_ext1.hdr");
	finalSi.diffAbs(base).saveImageAsHdr("correto/stirling_dif_ext1.hdr");
	std::cout << "Stirling: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalSi.calcDist(base) << std::endl;

}

void externalImages2()
{
	
	HdrImage base("ang13.hdr");

	HdrImage one("ang1.hdr");
	HdrImage two("ang2.hdr");
	HdrImage three("ang3.hdr");
	HdrImage four("ang4.hdr");
	HdrImage five("ang5.hdr");
	HdrImage six("ang6.hdr");
	HdrImage seven("ang7.hdr");
	HdrImage eight("ang8.hdr");
	HdrImage nine("ang9.hdr");
	HdrImage ten("ang10.hdr");
	HdrImage eleven("ang11.hdr");
	HdrImage twelve("ang12.hdr");
	HdrImage thirteen("ang13.hdr");
	HdrImage fourteen("ang14.hdr");
	HdrImage fifteen("ang15.hdr");
	HdrImage sixteen("ang16.hdr");
	HdrImage seventeen("ang17.hdr");
	HdrImage eighteen("ang18.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	/*imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);
	imagesToInterpolate.push_back(seven);*/
	imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	//imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	imagesToInterpolate.push_back(seventeen);
	imagesToInterpolate.push_back(eighteen);


	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(150);
	//observations.push_back(180);
	observations.push_back(210);
	observations.push_back(240);
	observations.push_back(270);
	observations.push_back(300);
	observations.push_back(330);

	LinearInterpolator li(observations, imagesToInterpolate);
	HdrImage finalLi = li.calculateInterpolationOn(180);
	finalLi.saveImageAsHdr("correto/linear_ext2.hdr");
	finalLi.diffAbs(base).saveImageAsHdr("correto/linear_dif_ext2.hdr");
	std::cout << "Linar: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator la(observations, imagesToInterpolate);
	HdrImage finalLa = la.calculateInterpolationOn(180);
	finalLa.saveImageAsHdr("correto/lagrange_ext2.hdr");
	finalLa.diffAbs(base).saveImageAsHdr("correto/lagrange_dif_ext2.hdr");
	std::cout << "Lagrange: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLa.calcDist(base) << std::endl;




	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(eight);
	//imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	//imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	//imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	//imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	//imagesToInterpolate.push_back(seventeen);
	imagesToInterpolate.push_back(eighteen);



	observations.clear();
	observations.push_back(30);
	//observations.push_back(60);
	observations.push_back(90);
	//observations.push_back(120);
	observations.push_back(150);
	//observations.push_back(180);
	observations.push_back(210);
	//observations.push_back(240);
	observations.push_back(270);
	//observations.push_back(300);
	observations.push_back(330);

	
	GaussianForwardInterpolator gfi(observations, imagesToInterpolate);
	HdrImage finalGfi = gfi.calculateInterpolationOn(180);
	finalGfi.saveImageAsHdr("correto/forward_ext2.hdr");
	finalGfi.diffAbs(base).saveImageAsHdr("correto/forward_dif_ext2.hdr");
	std::cout << "Forward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate);
	HdrImage finalGbi = gbi.calculateInterpolationOn(180);
	finalGbi.saveImageAsHdr("correto/backward_ext2.hdr");
	finalGbi.diffAbs(base).saveImageAsHdr("correto/backward_dif_ext2.hdr");
	std::cout << "Backward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate);
	HdrImage finalSi = si.calculateInterpolationOn(180);
	finalSi.saveImageAsHdr("correto/stirling_ext2.hdr");
	finalSi.diffAbs(base).saveImageAsHdr("correto/stirling_dif_ext2.hdr");
	std::cout << "Stirling: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalSi.calcDist(base) << std::endl;

}

void externalImages3()
{
	
	HdrImage base("ang17.hdr");

	HdrImage one("ang1.hdr");
	HdrImage two("ang2.hdr");
	HdrImage three("ang3.hdr");
	HdrImage four("ang4.hdr");
	HdrImage five("ang5.hdr");
	HdrImage six("ang6.hdr");
	HdrImage seven("ang7.hdr");
	HdrImage eight("ang8.hdr");
	HdrImage nine("ang9.hdr");
	HdrImage ten("ang10.hdr");
	HdrImage eleven("ang11.hdr");
	HdrImage twelve("ang12.hdr");
	HdrImage thirteen("ang13.hdr");
	HdrImage fourteen("ang14.hdr");
	HdrImage fifteen("ang15.hdr");
	HdrImage sixteen("ang16.hdr");
	HdrImage seventeen("ang17.hdr");
	HdrImage eighteen("ang18.hdr");


	std::vector<HdrImage> imagesToInterpolate;
	/*imagesToInterpolate.push_back(one);
	imagesToInterpolate.push_back(two);
	imagesToInterpolate.push_back(three);
	imagesToInterpolate.push_back(four);
	imagesToInterpolate.push_back(five);
	imagesToInterpolate.push_back(six);
	imagesToInterpolate.push_back(seven);*/
	imagesToInterpolate.push_back(eight);
	imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	//imagesToInterpolate.push_back(seventeen);
	imagesToInterpolate.push_back(eighteen);


	std::vector<int> observations;
	observations.push_back(30);
	observations.push_back(60);
	observations.push_back(90);
	observations.push_back(120);
	observations.push_back(150);
	observations.push_back(180);
	observations.push_back(210);
	observations.push_back(240);
	observations.push_back(270);
	//observations.push_back(300);
	observations.push_back(330);

	LinearInterpolator li(observations, imagesToInterpolate);
	HdrImage finalLi = li.calculateInterpolationOn(300);
	finalLi.saveImageAsHdr("correto/linear_ext3.hdr");
	finalLi.diffAbs(base).saveImageAsHdr("correto/linear_dif_ext3.hdr");
	std::cout << "Linar: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLi.calcDist(base) << std::endl;

	LaGrangeInterpolator la(observations, imagesToInterpolate);
	HdrImage finalLa = la.calculateInterpolationOn(300);
	finalLa.saveImageAsHdr("correto/lagrange_ext3.hdr");
	finalLa.diffAbs(base).saveImageAsHdr("correto/lagrange_dif_ext3.hdr");
	std::cout << "Lagrange: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalLa.calcDist(base) << std::endl;




	imagesToInterpolate.clear();
	imagesToInterpolate.push_back(eight);
	//imagesToInterpolate.push_back(nine);
	imagesToInterpolate.push_back(ten);
	//imagesToInterpolate.push_back(eleven);
	imagesToInterpolate.push_back(twelve);
	//imagesToInterpolate.push_back(thirteen);
	imagesToInterpolate.push_back(fourteen);
	//imagesToInterpolate.push_back(fifteen);
	imagesToInterpolate.push_back(sixteen);
	//imagesToInterpolate.push_back(seventeen);
	imagesToInterpolate.push_back(eighteen);



	observations.clear();
	observations.push_back(30);
	//observations.push_back(60);
	observations.push_back(90);
	//observations.push_back(120);
	observations.push_back(150);
	//observations.push_back(180);
	observations.push_back(210);
	//observations.push_back(240);
	observations.push_back(270);
	//observations.push_back(300);
	observations.push_back(330);

	
	GaussianForwardInterpolator gfi(observations, imagesToInterpolate);
	HdrImage finalGfi = gfi.calculateInterpolationOn(300);
	finalGfi.saveImageAsHdr("correto/forward_ext3.hdr");
	finalGfi.diffAbs(base).saveImageAsHdr("correto/forward_dif_ext3.hdr");
	std::cout << "Forward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGfi.calcDist(base) << std::endl;

	GaussianBackwardInterpolator gbi(observations, imagesToInterpolate);
	HdrImage finalGbi = gbi.calculateInterpolationOn(300);
	finalGbi.saveImageAsHdr("correto/backward_ext3.hdr");
	finalGbi.diffAbs(base).saveImageAsHdr("correto/backward_dif_ext3.hdr");
	std::cout << "Backward: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalGbi.calcDist(base) << std::endl;

	StirlingInterpolator si(observations, imagesToInterpolate);
	HdrImage finalSi = si.calculateInterpolationOn(300);
	finalSi.saveImageAsHdr("correto/stirling_ext3.hdr");
	finalSi.diffAbs(base).saveImageAsHdr("correto/stirling_dif_ext3.hdr");
	std::cout << "Stirling: " << std::fixed << std::setprecision( 1 ) << std::setfill( '0' ) << finalSi.calcDist(base) << std::endl;

}


void redMax(float &rmax, int &x, int &y, HdrImage img)
{
	rmax = 0;
	for(int i = 0; i < img.getWidth(); i++)
	{
		for(int j = 0; j < img.getWidth(); j++)
		{
			if( img.getPixelAt(i,j).red > rmax)
			{
				rmax = img.getPixelAt(i,j).red;
				x = i;
				y = j;
			}
		}
	}
}


#include "math2.h"


int main(int argc, char** argv) 
{
	DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));

	for(int i = 1; i < argc; i++)
	{
		fileRead(argv[i]);
	}


	cubicRootBetween0And1(1,0,-3,2);
	system("PAUSE");

	return 0;
};
