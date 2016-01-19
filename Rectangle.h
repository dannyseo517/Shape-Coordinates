#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<utility>
// headers, ...
#include "Shape.h"
#include "Point.h"
#include "ShapeVisitor.h"


class Rectangle: public Shape {
public:
  // read data for Rectangle from 'is'; used by factory
  // should read in data members saved by 'save' (except for the type name)
  // should perform some error-checking (see README)
  explicit Rectangle(std::istream& is);  

  // a Rectangle is specified by 2 (opposing) vertices
  // 'i' should be 0 or 1; if not, throw an exception
  Point getVertex(int i) const;

  // again, 'i' should be 0 or 1; if not, throw an exception
  void  setVertex(int i, const Point& p);

  // write to standard output
  // example output:  [R: (2,-3), (4,-5)]  
  virtual void draw() const; 

  /* example output:
       rectangle
       (2,-3) (4,-5)
  */
  virtual void save(std::ostream& os = std::cout) const; 
  
  // accept a visitor
  virtual void accept(ShapeVisitor& visitor); 

private:
  // not shown; provide suitable data structure
  Point vertex1_;
  Point vertex2_;
  
};

// provide inline implementation of getVertex & setVertex here
// implement the other functions in the CPP file
#endif
