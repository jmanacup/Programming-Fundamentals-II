#ifndef BOX_H
#define BOX_H

#include <iostream>

using namespace std;

class Box {

private:
	double length, width, height;
public:

	double getVolume();
	void setLength(double);
	void setBreadth(double);
	void setHeight(double);

	Box operator+(const Box&);
};

#endif
