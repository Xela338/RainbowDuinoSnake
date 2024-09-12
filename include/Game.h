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