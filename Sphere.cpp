#include "Sphere.h"
#include <iostream>
//Constructor
Sphere::Sphere(mwTPoint3d<double> _center, mwTPoint3d<double> _refPoint, double _rad, double _delta,
	unsigned long _nx, unsigned long _ny, unsigned long _nz) {
	center = _center;
	refPoint = _refPoint;
	rad = _rad;
	delta = _delta;

	nx = _nx;
	ny = _ny;
	nz = _nz;
}

//Default constructor
Sphere::Sphere() {
	center = mwTPoint3d<double>(0, 0, 0);
	refPoint = center;
	rad = 0;
	delta = 0;

	nx = ny = nz = 0;
}

//Method that get points of sphere 
std::vector<mwTPoint3d<unsigned long>> Sphere::getPointsOfSphere() {

	if (nz * delta + refPoint.z() > center.z() + rad) {
		return std::vector<mwTPoint3d<unsigned long>>();
	}

	//distance between center of sphere and small circle
	double heigth = (nz - 1) - center.z();

	//radius of small circle
	double smallRad = sqrt(rad * rad - heigth * heigth);

	//any (x,y,z) point is a grid point
	
	//xStart and xEnd 
	unsigned long xStart = (center.x() - smallRad - refPoint.x()) / delta + 1;
	unsigned long xEnd = (center.x() + smallRad - refPoint.x()) / delta;

	//yStart and yEnd
	unsigned long zStart = (center.z() - heigth - refPoint.z()) / delta;
	unsigned long zEnd = (center.z() - rad - refPoint.z()) / delta;

	//zStart and zEnd
	unsigned long yStart = (center.y() - smallRad - refPoint.y()) / delta + 1;
	unsigned long yEnd = (center.y() + smallRad - refPoint.y()) / delta;

	double dx, dy, dz;	//double (real) values of x and y
	double a, b, c;		//a - center.x, b - center.y, c - center.z
	a = center.x();
	b = center.y();
	c = center.z();

	mwTPoint3d<unsigned long> point;

	for (unsigned long x = xStart; x < xEnd + 1; x++) {
		dx = x * delta + refPoint.x();

		for (unsigned long y = yStart; y < yEnd + 1; y++) {
			dy = y * delta + refPoint.y();

				for (unsigned long z = zStart; z > zEnd - 1; z--) {
					dz = z * delta + refPoint.z();

					if (
						//if current point is in sphere
						isInSphere(rad, a, b, c, dx, dy, dz)
						&&
						// and the next point isn't
						!(isInSphere(rad, a, b, c, dx, dy, dz - delta))
						&&
						// and z is in grid
						z >= 0 && z < nz
						)
					{
						point = mwTPoint3d<unsigned long>(x, y, z - 1);
						spherePoints.push_back(point);
						break;
					}
				}
		}
	}

	return spherePoints;
}

bool Sphere::isInSphere(double rad, double a, double b, double c, double x, double y, double z) {
	if (
		(x - a) * (x - a) + (y - b) * (y - b) + (z - c) * (z - c) <= rad * rad
		) 
	{
		return true;
	}
	return false;
}
