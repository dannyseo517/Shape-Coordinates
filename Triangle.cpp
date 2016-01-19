#include "Triangle.h"
#include<iostream>
#include<string>
#include "TranslationVisitor.h"

Triangle::Triangle(std::istream& is){
	Point p1, p2, p3;
	if(is >> p1 >> p2 >> p3){
		vertex1_ = p1;
		vertex2_ = p2;
		vertex3_ = p3;
	}else{
		is.setstate(std::ios_base::failbit);
		throw "Triangle::failed constructor -- triangle Point Point Point";
	}
}
Point Triangle::getVertex(int i) const{
	if(i == 0)
		return vertex1_;
	else if(i == 1)
		return vertex2_;
	else if(i == 2)
		return vertex3_;
	else
		throw "Point getVertex(int i): the i must be 0,1 or 2";
}

void Triangle::setVertex(int i, const Point& p){
	if(i == 0)
		vertex1_ = p;
	else if(i == 1)
		vertex2_ = p;
	else if(i == 2)
		vertex3_ = p;
	else
		throw "Point getVertex(int i, const Point& p): the i must be 0,1 or 2";	
}

void Triangle::draw() const{
	std:: cout << "[T: " << getVertex(0) << ", " 
			   << getVertex(1) << ", " << getVertex(2) 
			   << "]" << std::endl;
}

void Triangle::save(std::ostream& os) const{
	os << "triangle" << std::endl;
	os << vertex1_ << ' ' << vertex2_ << ' ' << vertex3_ << std::endl;
}

void Triangle::accept(ShapeVisitor& v){
	v.visitTriangle(this);
}