//
// Created by piotr on 05.04.2017.
//

#include "Point.h"
#include <iomanip>
#include <iostream>

using ::std::istream;
using ::std::ws;

Point::Point():x_(0),y_(0){}
Point::Point(double x, double y){
    this->x_ = x;
    this->y_ = y;
}
Point::~Point(){}
double Point::GetX() const{
    return x_;
}
double Point::GetY() const{
    return y_;
}
void Point::SetX(double x){
    this->x_ = x;
}
void Point::SetY(double y){
    this->y_ = y;
}
//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}
void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}
double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}
// Właściwa definicja, obydwa argumenty funkcji nie
//są zadeklarowane jako const, bo obydwa są modyfikowane
//wewnątrz funkcji (STL nie używa naszej konwencji z przekazywaniem
//przez wskaźnik)
istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}

istream& operator<<(istream & output, Point& p){
    output<<p.GetX()<<' '<<p.
    return output;
}