TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    cutSphereMove.cpp \
		CreateSkin.cpp \
    mwException.cpp \
		mwArcFunction.cpp \
    mwIdxRangeException.cpp


HEADERS += \
		CreateSkin.hpp \
    mwDiscreteFunction.hpp \
    mwException.hpp \
    mwIdxRangeException.hpp \
		mwArcFunction.hpp \
		mwDiscreteFunction.hpp \
    mwMathConstants.hpp \
    mwTPoint3d.hpp

