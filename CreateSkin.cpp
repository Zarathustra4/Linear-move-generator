#include "CreateSkin.hpp"
#include "LinMove.h"
#include "Skin.h"

#include <iostream>
#include <chrono>

void CreateSkin( const cadcam::mwTPoint3d<double> refPoint, 
				const unsigned long nx, const unsigned long ny, 
				const unsigned long nz, const double sphereRad, 
				mwDiscreteFunction &func, const double deltaT, 
				const double delta, const std::string &skinFileName )
{
	/*
	Every point in skin is designed as point of grid with unsigned long type of each coordinate.
	Using unsigned long type of coordinates is more accurate in computations and comparing than using double ones.
	*/
	std::cout << ">>Start of work...\n";
	auto start = std::chrono::high_resolution_clock::now();
	
	//Linear move of sphere
	LinMove l(func, refPoint, delta, deltaT, sphereRad, nx, ny, nz);

	//Grid, which takes points of linear move and creates the skin
	Skin s(nx, ny, nz, delta, skinFileName, l.getPointMap(), refPoint);

	auto finish = std::chrono::high_resolution_clock::now();

	std::cout << ">>End of work!\n";
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}
