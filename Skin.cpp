#include "Skin.h"
#include <iostream>

//constructor that generates points of skin and write it into file using PointWriter
Skin::Skin(unsigned long _nx, unsigned long _ny, unsigned long _nz, double delta,
	std::string fileName, std::map<std::array<unsigned long, 2>, unsigned long> _linMovePoints, mwTPoint3d<double> _refPoint) {
	
	std::cout << "Begin of generating skin\n";

	nx = _nx;
	ny = _ny;
	nz = _nz;

	refPoint = _refPoint;

	pointWriter = PointWriter(fileName);

	linMovePoints = _linMovePoints;

	mwTPoint3d<unsigned long> point;

	std::array<unsigned long, 2> x_y;

	std::vector<mwTPoint3d<unsigned long>> skinPoints;

	//default value of z
	unsigned long z = nz - 1;
	
	for (unsigned long x = 0; x < nx; x++) {
		x_y[0] = x;
		for (unsigned long y = 0; y < ny; y++) {
			x_y[1] = y;
			
			if (linMovePoints[x_y]) {
				//if such (x,y) exists in the map
				point = mwTPoint3d<unsigned long>(x, y, linMovePoints[x_y]);
				skinPoints.push_back(point);
			}
			else {
				point = mwTPoint3d<unsigned long>(x, y, z);
				skinPoints.push_back(point);
			}
		}
	}

	std::cout << "End of generating skin\n\n";

	std::cout << "Begin of writing to the file\n";
	pointWriter.writeToFile(skinPoints, delta, refPoint, true);
	std::cout << "End of writing to the file\n";
}
