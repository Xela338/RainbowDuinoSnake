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