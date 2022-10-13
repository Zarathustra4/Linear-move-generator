#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "mwTPoint3d.hpp"

using cadcam::mwTPoint3d;

class PointWriter
{
private:
	std::ofstream fileWriter;

	std::string filePath;

	double delta;

	mwTPoint3d<double> refPoint;

public:
	PointWriter(std::string fileName, double delta, mwTPoint3d<double> refPoint);

	void writeToFile(std::vector<mwTPoint3d<unsigned long>> points);

};

