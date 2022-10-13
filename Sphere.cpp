#include "Sphere.h"

Sphere::Sphere() {
	center = mwTPoint3d<double>();
	rad = 0;
}

Sphere::Sphere(mwTPoint3d<double> _center, double _rad) {
	center = _center;
	rad = _rad;
}

double Sphere::getZ(double x, double y, double defaultValue) {
	//if (x,y) is in sphere, return z value, else return default value of z


	double a, b; //center.x, center.y

	a = center.x();
	b = center.y();

	if ((x - a) * (x - a) + (y - b) * (y - b) > rad * rad) {
		return defaultValue;
	}

	if (center.z() + rad < defaultValue || center.z() - rad > defaultValue) {
		return defaultValue;
	}

	double z = -sqrt( pow(rad, 2) - pow(x - center.x(), 2) - pow(y - center.y(), 2) ) + center.z();

	return z;
}