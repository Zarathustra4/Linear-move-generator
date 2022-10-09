#include "LinMove.h"
#include <iostream>

LinMove::LinMove(mwDiscreteFunction& func, mwTPoint3d<double> _refPoint, 
	double _delta, double _deltaT, double _rad,
	unsigned long _nx, unsigned long _ny, unsigned long _nz) {
	refPoint = _refPoint;
	delta = _delta;
	deltaT = _deltaT;
	rad = _rad;

	nx = _nx;
	ny = _ny;
	nz = _nz;

	generateMove(func);
}


void LinMove::generateMove(mwDiscreteFunction& func) {
	std::cout << "Begin of generating lin move\n";

	double beginParam = func.GetBeginParameter();
	double endParam = func.GetEndParameter();

	mwTPoint3d<double> center1;
	mwTPoint3d<double> center2;

	unsigned long moveCount = (endParam - beginParam) / deltaT;

	//distance between center1 and center2
	double moveDistance;

	Sphere s;

	std::vector<mwTPoint3d<double>> spherePoints;

	for (unsigned long i = 0; i < moveCount; i++) {
		center1 = func.Evaluate(beginParam + i * deltaT);
		center2 = func.Evaluate(beginParam + (i + 1) * deltaT);

		moveDistance = sqrt((center2 - center1) * (center2 - center1));

		//count of small moves
		unsigned long smallMoveCount = moveDistance / delta + 1;

		double vectorCoef = delta / moveDistance;

		for (unsigned long j = 0; j < smallMoveCount; j++) {
			s = Sphere(center1 + (center2 - center1) * vectorCoef * j, refPoint, rad, delta, nx, ny, nz);

			fillMap(s.getPointsOfSphere());
		}
	}

	std::cout << "End of generating lin move\n\n";
}


std::map <std::array<unsigned long, 2>, unsigned long> LinMove::getPointMap() {
	return pointMap;
}

void LinMove::fillMap(std::vector<mwTPoint3d<unsigned long>>& pointsVec) {
	//the function goes through a vector and fills the map
	//for every (x, y) should be the least z
	std::array <unsigned long, 2> x_y;
	for (auto& point : pointsVec) {
		
		x_y[0] = point.x();
		x_y[1] = point.y();

		if (pointMap[x_y]) {
			if (pointMap[x_y] > point.z()) {
				pointMap[x_y] = point.z();
			}
		}
		else {
			pointMap[x_y] = point.z();
		}
	}
}