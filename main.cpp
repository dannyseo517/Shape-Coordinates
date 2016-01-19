#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapeFactory.h"
#include "ShapeVisitor.h"
#include "TranslationVisitor.h"
#include "XReflectionVisitor.h"
#include "YReflectionVisitor.h"
#include "Point.h"

using namespace std;
int main(int argc, char *argv[]){

	vector<Shape*> v;
	ShapeFactory sf(cin);
	Shape *p;
	string cmd;
	
	if (argc != 2) {
		cerr << "usage: " << argv[0] << " {data-file}" << endl;	
		return 1;
	}
	fstream fs(argv[1], ios::in|ios::out|ios::binary);
	
	
	if(!fs){
		cerr  << "unable to open file" << endl;
	}else{
		ShapeFactory sff(fs);
		while((p = sff.create()) != 0){
			v.push_back(p);
		}
		for(auto s: v){
			s->draw();
		}
	}
	while(cerr << "> " && cin >> cmd){
		
		if(cmd =="c"){
			try{
				if((p = sf.create()) != 0){
					v.push_back(p);
					for(auto s: v){
						s->draw();
					}
				}
			}catch(const char *s){
				cerr << s << endl;
			}
		}
		else if(cmd == "t"){
			Point pt;
			cin >> pt;
			ShapeVisitor *sp = new TranslationVisitor(pt);
			for(auto s: v){
				s->accept(*sp);
				s->draw();
			}
		}
		else if(cmd == "x"){
			ShapeVisitor *sp = new XReflectionVisitor();
			for(auto s: v){
				s->accept(*sp);
				s->draw();
			}
		}
		else if(cmd == "y"){
			ShapeVisitor *sp = new YReflectionVisitor();
			for(auto s: v){
				s->accept(*sp);
				s->draw();
			}
		}else if(cmd == "d"){
			for(auto s: v){
				s->draw();
			}
		}
	}
	fs.close();
	ofstream outfile(argv[1], ios::binary);
	for(auto s: v){
		s->save(outfile);
	}
	outfile.close();
}