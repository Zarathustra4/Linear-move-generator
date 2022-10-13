#include <vector>
#include <math.h>
#include "mwTPoint3d.hpp"
#include "mwDiscreteFunction.hpp"

#pragma once

using cadcam::mwTPoint3d;

class LinMove
{
private:
	std::vector<mwTPoint3d<double>> movePoints;

public:
	LinMove(mwDiscreteFunction& func, double deltaT);
	
	std::vector<mwTPoint3d<double>> getMove();
};

