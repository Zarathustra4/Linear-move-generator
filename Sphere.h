#include <vector>
#include "mwTPoint3d.hpp"

#pragma once

using cadcam::mwTPoint3d;
//Sphere class, creates points of sphere, which are in grid too. 
class Sphere
{
private:
	//center of sphere
	mwTPoint3d<double> center;

	//reference Point
	mwTPoint3d<double> refPoint;

	//sphere radius
	double rad;

	//delta of grid
	double delta;

	//points of sphere that are needed for creating skin
	std::vector<mwTPoint3d<unsigned long>> spherePoints;

	//number of grid points
	unsigned long nx;
	unsigned long ny;
	unsigned long nz;


public:
	//constructor
	Sphere(mwTPoint3d<double> _center, mwTPoint3d<double> _refPoint, double _rad, double _delta,
			unsigned long _nx,unsigned long _ny, unsigned long _nz );
	
	//default constructor
	Sphere();
	
	//getPointsOfSphere generates std::vector of points, that is needed for skin and returns it
	std::vector<mwTPoint3d<unsigned long>> getPointsOfSphere();

private:
	//checks whether a point is in a sphere
	bool isInSphere(double rad, double a, double b, double c, double x, double y, double z);
};
