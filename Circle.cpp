#include "Circle.h"
#include<iostream>
#include<string>
#include "TranslationVisitor.h"

Circle::Circle(std::istream& is){
	int r;
	Point c;
	if(is >> c >> r){
		centre_ = c;
		radius_ = r;
	}else if(radius_ < 0){
		throw "Circle::Circle(const Point&, int, const Colour&): invalid radius";
	}else{
		is.setstate(std::ios_base::failbit);
		throw "Circle::failed constructor -- circle Point int";
	}
}

 void Circle::draw() const{
	std::cout << "[C: " << getCentre() << ", " << getRadius() << "]"<< std::endl;
 }
 
 void Circle::save(std::ostream& os) const{
	os << "circle" << std::endl;
	os << centre_ << ' ' << radius_ << std::endl;
 }
 
 void Circle::accept(ShapeVisitor& v){
	 v.visitCircle(this);
 }