#include "mwTPoint3d.hpp"
#include <math.h>

#pragma once

using cadcam::mwTPoint3d;

class Sphere
{
private:
	mwTPoint3d<double> center;
	double rad;

public:
	Sphere();
	Sphere(mwTPoint3d<double> _center, double _rad);

	//if (x,y) is in sphere, return z value, else return default value of z
	double getZ(double x, double y, double defaultValue);
};

