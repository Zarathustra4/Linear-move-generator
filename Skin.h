#include <vector>
#include <math.h>
#include <iostream>

#include "mwTPoint3d.hpp"
#include "Sphere.h"

#pragma once

using cadcam::mwTPoint3d;

class Skin
{
private:

	//sizes of grid
	unsigned long nx;
	unsigned long ny;
	unsigned long nz;

	//move points
	std::vector<mwTPoint3d<double>> movePoints;

	//skin points
	std::vector<mwTPoint3d<unsigned long>> skinPoints;

	//sphere radius
	double rad;

	//delta
	double delta;

	//reference point
	mwTPoint3d<double> refPoint;

	//default z value, which cannot be displayed
	double zDefault;

public:
	//constructor
	Skin(unsigned long gridSize[], std::vector<mwTPoint3d<double>> movePoints, double rad, double delta, mwTPoint3d<double> _refPoint);

	//returns skin points
	std::vector<mwTPoint3d<unsigned long>> getSkinPoints();

private:
	//generates skin
	void generateSkin();

	//returns double value of z
	double getZ(double x, double y);

	//finds center (perpendicular) for a point
	mwTPoint3d<double> findCenter(mwTPoint3d<double> start, mwTPoint3d<double> end, mwTPoint3d<double> point);

	//checks whether point is in the segment
	bool isInSegment(mwTPoint3d<double> point, mwTPoint3d<double> start, mwTPoint3d<double> end);

};

