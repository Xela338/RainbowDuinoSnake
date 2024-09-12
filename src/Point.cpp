/*
    Copyright (c) 2024 Kotaro Morimoto

    This program is free software: you can redistribute it and/or 
    modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
    See the GNU General Public License for more details.

    You should have received a copy of the 
    GNU General Public License along with this program. 
    If not, see <https://www.gnu.org/licenses/>. 
*/

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