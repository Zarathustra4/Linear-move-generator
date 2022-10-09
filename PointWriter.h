#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include "mwTPoint3d.hpp"

using cadcam::mwTPoint3d;

class PointWriter
{
private:

	std::string filePath;
	std::ofstream fileWriter;

public:
	//Constructor
	PointWriter(std::string);
	
	//Default constructor
	PointWriter();

	//writes vector elements to the file
	void writeToFile(std::vector<mwTPoint3d<unsigned long>> points, double delta, mwTPoint3d<double> refPoint, bool firstWrite = false);
};