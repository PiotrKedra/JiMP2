//
// Created by piotr on 23.03.2017.
//

#include "Point.h"
#include <cmath>
#include <ostream>
#include <iostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

namespace geometry {
    Point::Point():x(0),y(0){}

    Point::Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    Point::~Point(){}
    double Point::GetX() const{
        return x;
    }
    double Point::GetY() const{
        return y;
    }
    void Point::SetX(double x){
        this->x = x;
    }
    void Point::SetY(double y){
        this->y = y;
    }
    double Point::Distance(const Point &other) const{
        return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));

    }
    void Point::ToString(ostream *out) const{
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }
}
