#include <iostream>
#include "Box.h"

using namespace std;

double Box::getVolume() {
	return length * width * height;
}
void Box::setLength(double length) {
	this->length = length;
}
void Box::setBreadth(double width) {
	this->width = width;
}
void Box::setHeight(double height) {
	this->height = height;
}
Box Box::operator+(const Box& right) {

	length += right.length;
	width += right.width;
	height += right.height;

	return *this;
}