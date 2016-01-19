#include "TranslationVisitor.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include<iostream>
#include<string>


void TranslationVisitor::visitCircle(Circle *s){
	Point centre = s->getCentre();
	centre += d_;
	s->setCentre(centre);	
}

void TranslationVisitor::visitTriangle(Triangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	Point v3 = s->getVertex(2);
	
	v1 += d_;
	v2 += d_;
	v3 += d_;
	
	s->setVertex(0, v1);
	s->setVertex(1, v2);
	s->setVertex(2, v3);
}

void TranslationVisitor::visitRectangle(Rectangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	
	v1 += d_;
	v2 += d_;
	
	s->setVertex(0,v1);
	s->setVertex(1,v2);
}