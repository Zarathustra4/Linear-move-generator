#pragma once
#include "mwDiscreteFunction.hpp"
#include "mwTPoint3d.hpp"
#include "Sphere.h"
#include <vector>
#include <map>
#include <math.h>
#include <array>

using cadcam::mwTPoint3d;

class LinMove
{
private:
	//reference point
	mwTPoint3d<double> refPoint;

	//delta
	double delta;

	//delta T
	double deltaT;

	//sphere radius
	double rad;

	//map with the least of z for all (x, y) in move
	std::map <std::array<unsigned long, 2>, unsigned long> pointMap;

	//sizes of grid
	unsigned long nx;
	unsigned long ny;
	unsigned long nz;

public:
	//constructor that calls generateMove method to have pointsSet done
	LinMove(mwDiscreteFunction& func, mwTPoint3d<double> _refPoint, double _delta, double _deltaT, double _rad,
		unsigned long _nx, unsigned long _ny, unsigned long _nz);

	//map of form { ( x, y ) : z }
	std::map <std::array <unsigned long, 2>, unsigned long> getPointMap();


private:
	//generates points of move
	void generateMove(mwDiscreteFunction& func);

	//fills coordinates map
	void fillMap(std::vector<mwTPoint3d<unsigned long>>&);
};

