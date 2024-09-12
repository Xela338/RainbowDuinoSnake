#pragma once

struct Point{
    Point(double x,double y):x(x),y(y){};
    Point(const Point& p):x(p.x),y(p.y){};
    double x;
    double y;
    Point round_down();
};

bool operator==(const Point& left,const Point& right);
bool operator!=(const Point& left,const Point& right);

bool operator<(const Point& left,const Point& right);

Point operator+(const Point& left,const Point& right);

template<typename T>
Point operator*(const Point& left,const T& right){
    return Point(left.x*right,left.y*right);
}