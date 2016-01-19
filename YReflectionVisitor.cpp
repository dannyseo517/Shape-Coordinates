#include "YReflectionVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <string>

void YReflectionVisitor::visitCircle(Circle *s){
	Point centre = s->getCentre();
	int x_new = 0 - centre.getX();
	centre.setX(x_new);
	s->setCentre(centre);
}

void YReflectionVisitor::visitRectangle(Rectangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	int x1_new = 0 - v1.getX();
	int x2_new = 0 - v2.getX();
	v1.setX(x1_new);
	v2.setX(x2_new);
	s->setVertex(0, v1);
	s->setVertex(1, v2);
	
}

void YReflectionVisitor::visitTriangle(Triangle *s){
	Point v1 = s->getVertex(0);
	Point v2 = s->getVertex(1);
	Point v3 = s->getVertex(2);
	int x1_new = 0 - v1.getX();
	int x2_new = 0 - v2.getX();
	int x3_new = 0 - v3.getX();
	v1.setX(x1_new);
	v2.setX(x2_new);
	v3.setX(x3_new);
	s->setVertex(0, v1);
	s->setVertex(1, v2);
	s->setVertex(2, v3);
}