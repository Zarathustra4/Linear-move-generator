#pragma once
#include "LinMove.h"
#include "PointWriter.h"
#include "mwTPoint3d.hpp"

#include <set>
#include <vector>
#include <string>
#include <map>
#include <array>

using cadcam::mwTPoint3d;
class Skin
{
private:
	unsigned long nx;
	unsigned long ny;
	unsigned long nz;

	double delta;
	PointWriter pointWriter;
	mwTPoint3d<double> refPoint;

	//points of linear move
	std::map<std::array<unsigned long, 2>, unsigned long> linMovePoints;

public:
	//constructor that generates points of skin and write it into file using PointWriter
	Skin(unsigned long _nx, unsigned long _ny, unsigned long _nz, double delta,
		std::string fileName, std::map<std::array<unsigned long, 2>, unsigned long> _linMovePoints, mwTPoint3d<double> _refPoint);

};