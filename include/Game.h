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

#include <Rainbowduino.h>
#include <Arduino.h>
#include <vector>
#include <list>
#include <Point.h>

constexpr float speed = 2.5;

struct Game{
    Rainbowduino rd = Rainbowduino();
    bool was_update = false;
    std::list<Point> snake;
    Point vec = Point(0,-speed);
    Point food = Point(6,4);
    uint64_t pre_frame_time = 0;

    Game():
        snake(std::list<Point>()){};
    void init();
    void reset();
    void update(uint16_t delta_time,uint8_t input);
    void show();
};