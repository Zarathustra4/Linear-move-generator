#include "LinMove.h"

LinMove::LinMove(mwDiscreteFunction& func, double deltaT) {
	double tBegin = func.GetBeginParameter();
	double tEnd = func.GetEndParameter();

	double t;

	unsigned long moveCount = (tEnd - tBegin) / deltaT ;
	
	for (unsigned long i = 0; i < moveCount; i++) {
		t = tBegin + i * deltaT;
		movePoints.push_back(func.Evaluate(t));
	}
}

std::vector<mwTPoint3d<double>> LinMove::getMove() {
	return movePoints;
}