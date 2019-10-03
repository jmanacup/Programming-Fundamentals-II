#ifndef BOX_H
#define BOX_H

#include <iostream>

using namespace std;

class Box {

private:
	//member variables
	double length, width, height;
public:

	//function prototypes
	double getVolume();
	void setLength(double);
	void setBreadth(double);
	void setHeight(double);
	Box operator+(const Box&);
};

#endif
