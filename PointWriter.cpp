#include "PointWriter.h"
#include <iostream>

PointWriter::PointWriter(std::string fileName, double _delta, mwTPoint3d<double> _refPoint) {
	filePath = fileName;
	delta = _delta;
	refPoint = _refPoint;
}


void PointWriter::writeToFile(std::vector<mwTPoint3d<unsigned long>> points) {

	fileWriter = std::ofstream(filePath);

	if (!fileWriter) {
		std::cout << "Can not open " << filePath << " file!!!";
		return;
	}


	mwTPoint3d<double> doublePoint;
	for (auto& point : points) {
			
		doublePoint = mwTPoint3d<double>(point.x(), point.y(), point.z());
		doublePoint *= delta;
		doublePoint += refPoint;

		fileWriter << doublePoint.x() << " " << doublePoint.y() << " " << doublePoint.z() << "\n";
	}
	fileWriter.close();
}