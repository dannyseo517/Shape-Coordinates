#include "Rectangle.h"
#include<iostream>
#include<string>
#include "TranslationVisitor.h"

Rectangle::Rectangle(std::istream& is){
	Point p1, p2;
	if(is >> p1 >> p2){
		vertex1_ = p1;
		vertex2_ = p2;
	}else{
		is.setstate(std::ios_base::failbit);
		throw "Rectangle::failed constructor -- rectangle Point Point";
	}
}
Point Rectangle::getVertex(int i) const{
	if(i == 0)
		return vertex1_;
	else if(i == 1)
		return vertex2_;
	else
		throw "Point getVertex(int i): the i must be 0 or 1";
  }
void Rectangle::setVertex(int i, const Point& p){
	if(i == 0)
		vertex1_ = p;
	else if( i == 1)
		vertex2_ = p;
	else
		throw "Point getVertex(int i, const Point& p): the i must be 0 or 1";
}

void Rectangle::draw() const{
	std:: cout << "[R: " << getVertex(0) << ", " << getVertex(1)
			   << "]" << std::endl;
}

void Rectangle::save(std::ostream& os) const{
	os << "rectangle" << std::endl;
	os << vertex1_ << ' ' << vertex2_ << ' ' << std::endl;
}

void Rectangle::accept(ShapeVisitor& v){
	v.visitRectangle(this);
}