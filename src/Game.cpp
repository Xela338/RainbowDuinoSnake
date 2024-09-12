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

#include <Game.h>
#include <Rainbowduino.h>

constexpr uint32_t color = 0xffffff;

void Game::init(){
    rd.init();
    rd.clearDisplay();
    snake.push_front(Point(6,7));
}

void Game::reset(){
    food = Point(6,4);
    vec = Point(0,-speed);
    snake.clear();
    snake.push_front(Point(6,7));
}

void Game::update(uint16_t delta_time,uint8_t input){
    was_update = false;

    // 現在地を保存し、前進する
    Point before = *snake.begin();
    *snake.begin() =before+vec*(delta_time/1000.0);

    // 1ピクセル以上進んでいたら、体も前進させる
    if(before.round_down() != (*snake.begin()).round_down()){
        was_update = true;
        snake.insert(++snake.begin(),before.round_down());

        // 頭が餌に触れていないなら最後尾を削除
        if((*snake.begin()).round_down() != food){
            snake.pop_back();
        }else{
            food=Point(random()%6+1,random()%6+1);
        }
    }

    Point head = (*snake.begin()).round_down();
    if(head.x < 0 || head.x > 7 || head.y < 0 || head.y > 7 ){
        reset();
    }
}

void Game::show(){
    if(was_update){
        rd.blankDisplay();
        Point pos(0,0);
        for(auto itr = ++snake.begin();itr!=snake.end();itr++){
            pos = (*itr).round_down();
            rd.setPixelXY(pos.x,pos.y,color);
        }
        pos = (*snake.begin()).round_down();
        rd.setPixelXY(pos.x,pos.y,0xff0000);

        rd.setPixelXY(food.x,food.y,0x00ff00);
    }
}