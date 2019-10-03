#include <iostream>
#include "Box.h"

using namespace std;

//function definitions
double Box::getVolume() { //gets the total volume of the box
	return length * width * height;
}
//mutators
void Box::setLength(double length) {
	this->length = length;
}
void Box::setBreadth(double width) {
	this->width = width;
}
void Box::setHeight(double height) {
	this->height = height;
}

//operator overloading for +
Box Box::operator+(const Box& right) {

	length += right.length;
	width += right.width;
	height += right.height;

	return *this;
}