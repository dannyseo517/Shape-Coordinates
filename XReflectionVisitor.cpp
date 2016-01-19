#include "XReflectionVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <string>

void XReflectionVisitor::visitCircle(Circle *s){
	Point centre = s->getCentre();
	int y_new = 0 - centre.getY();
	centre.setY(y_new);
	s->setCentre(centre);
}

void XReflectionVisitor::visitRectangle(Rectangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	int y1_new = 0 - v1.getY();
	int y2_new = 0 - v2.getY();
	v1.setY(y1_new);
	v2.setY(y2_new);
	s->setVertex(0, v1);
	s->setVertex(1, v2);
	
}

void XReflectionVisitor::visitTriangle(Triangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	Point v3 = s->getVertex(2);
	int y1_new = 0 - v1.getY();
	int y2_new = 0 - v2.getY();
	int y3_new = 0 - v3.getY();
	v1.setY(y1_new);
	v2.setY(y2_new);
	v3.setY(y3_new);
	s->setVertex(0, v1);
	s->setVertex(1, v2);
	s->setVertex(2, v3);
}