#include "PointWriter.h"

using cadcam::mwTPoint3d;

//constructor
PointWriter::PointWriter(std::string fileName) {
	filePath = fileName;
}

//default constructor
PointWriter::PointWriter() {
	filePath = "";
}

void PointWriter::writeToFile(std::vector<mwTPoint3d<unsigned long>> points, double delta, mwTPoint3d<double> refPoint, bool firstWrite) {
	/*
	Every point in skin is designed as point of grid with unsigned long type of each coordinate.
	This method converts the point to double and after that write into file.
	Using unsigned long type of coordinates is more accurate in computations than using double ones.
	*/

	if (firstWrite) {
		fileWriter = std::ofstream(filePath); //clear the file and than write
	}
	else {
		fileWriter = std::ofstream(filePath, std::ios_base::app); //append mode
	}

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