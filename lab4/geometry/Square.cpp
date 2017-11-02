//
// Created by piotr on 22.03.2017.
//

#include "Square.h"
#include "Point.h"
#include <cmath>
#include <ostream>
#include <iostream>

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;


namespace geometry {
    Square::Square() {}
    Square::Square(Point pp1, Point pp2, Point pp3, Point pp4):
            p1(pp1),p2(pp2),p3(pp3),p4(pp4)
    {
        if(p1.Distance(p2)==p2.Distance(p4) and p4.Distance(p3)==p3.Distance(p1) and
                p1.Distance(p2)==p3.Distance(p4) and p1.Distance(p4)==p2.Distance(p3)){}
        else{
            if_square = false;
        }
    }
    Square::~Square() {}

    double Square::Circumference(){
        if(!if_square) return 0;
        std::cout << 4*p1.Distance(p2) << "fsddd-ahsekf fhakia kkaf a asfhafs ihuiwehr8923y58023y508y4y3q85y3 87" << std::endl;
        return 4*p1.Distance(p2);
    }

    double Square::Area(){
        if(!if_square) return 0;
        return pow(p1.Distance(p2),2);
    }

}