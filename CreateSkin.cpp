#include "CreateSkin.hpp"
#include "Skin.h"
#include "LinMove.h"
#include "PointWriter.h"

void CreateSkin( const cadcam::mwTPoint3d<double> refPoint, 
				const unsigned long nx, const unsigned long ny, 
				const unsigned long nz, const double sphereRad, 
				mwDiscreteFunction &func, const double deltaT, 
				const double delta, const std::string &skinFileName )
{
	LinMove l(func, deltaT);
	unsigned long size[3] = { nx, ny, nz };
	Skin s(size, l.getMove(), sphereRad, delta, refPoint);
	PointWriter pw(skinFileName, delta, refPoint);

	pw.writeToFile(s.getSkinPoints());
}
