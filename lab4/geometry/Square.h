//
// Created by piotr on 22.03.2017.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

#include "Point.h"


namespace geometry{
    class Square{
    public:
        Square();
        Square(Point pp1, Point pp2, Point pp3, Point pp4);
        ~Square();

        double Circumference();
        double Area();


    private:
        Point p1,p2,p3,p4;
        bool if_square = true;
    };
}
#endif //JIMP_EXERCISES_SQUARE_H
