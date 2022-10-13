#include "Skin.h"
Skin::Skin(unsigned long gridSize[], std::vector<mwTPoint3d<double>> _movePoints, double _rad, double _delta, mwTPoint3d<double> _refPoint) {
	nx = gridSize[0];
	ny = gridSize[1];
	nz = gridSize[2];

	movePoints = _movePoints;
	rad = _rad;
	delta = _delta;

	refPoint = _refPoint;

	//default value of z, if (x,y) are not in move
	zDefault = nz * delta + refPoint.z();

	generateSkin();
}

void Skin::generateSkin() {
	std::cout << "Generate skin\n";

	unsigned long x, y, z;
	z = nz - 1;
	double dx, dy, dz;

	mwTPoint3d<unsigned long> point;

	for (x = 0; x < nx + 1; x++) {
		dx = x * delta + refPoint.x();

		for (y = 0; y < ny + 1; y++) {
			dy = y * delta + refPoint.y();

			dz = getZ(dx, dy);

			if (dz < zDefault) {
				z = (dz - refPoint.z()) / delta;
				point = mwTPoint3d<unsigned long> (x, y, z);
				skinPoints.push_back(point);
			}

			else {
				point = mwTPoint3d<unsigned long>(x, y, nz);
				skinPoints.push_back(point);
			}
		}
	}

	std::cout << "End of generate skin\n";
}

std::vector<mwTPoint3d<unsigned long>> Skin::getSkinPoints() {
	return skinPoints;
}

double Skin::getZ(double x, double y) {
	//returns double value of z

	mwTPoint3d < double > moveStart;
	mwTPoint3d < double > moveEnd;

	mwTPoint3d < double > center;

	mwTPoint3d < double > moveVec;

	double z;

	mwTPoint3d < double > point(x, y, 0);

	Sphere sphere;

	for (unsigned long i = 0; i < movePoints.size() - 1; i++) {

		moveStart = movePoints[i];
		moveEnd = movePoints[i + 1];

		moveVec = moveEnd - moveStart;


		center = findCenter(moveStart, moveEnd, point);

		if (!isInSegment(center, moveStart, moveEnd)) {
			//if center is not in segment, define center as move start point

			sphere = Sphere(moveStart, rad);
			z = sphere.getZ(x, y, zDefault);

			if (z != zDefault)
				return z;

			if (i == movePoints.size() - 2) {
				//for the last point
			
				sphere = Sphere(moveEnd, rad);
				z = sphere.getZ(x, y, zDefault);

				if (z != zDefault)
					return z;
			}
			
			continue;
		}

		sphere = Sphere(center, rad);

		z = sphere.getZ(x, y, zDefault);

		if (z == zDefault)
			continue;

		return z;
	}
	return zDefault;
}

mwTPoint3d<double> Skin::findCenter(mwTPoint3d<double> start, mwTPoint3d<double> end, mwTPoint3d<double> point) {
	//returns the coordinates of the perpendicular (center of sphere) to the line of linear move


	//distances between the points
	double start_center, start_end, start_point, end_point;

	start_end = sqrt((end - start) * (end - start));

	start_point = sqrt((start - point) * (start - point));

	end_point = sqrt((end - point) * (end - point));

	start_center = (pow(end_point, 2) - pow(start_end, 2) - pow(start_point, 2)) / (-2 * start_end);

	double coef = start_center / start_end;

	mwTPoint3d<double> center = start + (end - start) * coef;


	return center;
}

bool Skin::isInSegment(mwTPoint3d<double> point, mwTPoint3d<double> start, mwTPoint3d<double> end) {
	//the method checks whether point is in segment


	double xMax, xMin;
	double yMax, yMin;
	double zMax, zMin;

	if (start.x() < end.x()) {
		xMax = end.x();
		xMin = start.x();
	}
	else {
		xMin = end.x();
		xMax = start.x();
	}


	if (start.y() < end.y()) {
		yMax = end.y();
		yMin = start.y();
	}
	else {
		yMin = end.y();
		yMax = start.y();
	}


	if (start.z() < end.z()) {
		zMax = end.z();
		zMin = start.z();
	}
	else {
		zMin = end.z();
		zMax = start.z();
	}

	zMin -= rad;
	zMax += rad;


	if (
		point.x() >= xMin && point.x() <= xMax
		&&
		point.y() >= yMin && point.y() <= yMax
		&&
		point.z() >= zMin && point.z() <= zMax
		) 
	{
		return true;
	}
	return false;

}
