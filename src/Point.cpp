#include <Point.h>

bool operator==(const Point& left,const Point& right){
    return (left.x == right.x) && (left.y == right.y);
}

bool operator!=(const Point& left,const Point& right){
    return !(left==right);
}

bool operator<(const Point& left,const Point& right){
    if(left.x == right.x)return left.y < right.y;
    return left.x < right.x;
}

Point operator+(const Point& left,const Point& right){
    return Point(left.x + right.x,left.y + right.y);
}

Point Point::round_down(){
    return Point(static_cast<int>(x),static_cast<int>(y));
}