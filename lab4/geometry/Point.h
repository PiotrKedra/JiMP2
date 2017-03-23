//
// Created by piotr on 23.03.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <ostream>

namespace geometry {
    class Point {
    public:
        Point();
        Point(double x, double y);
        ~Point();

        double Distance(const Point &other) const;
        void ToString(std::ostream *out) const;

        double GetX() const;
        double GetY() const;

        void SetX(double x);
        void SetY(double y);

    private:
        double x;
        double y;
    };
}
#endif //JIMP_EXERCISES_POINT_H
