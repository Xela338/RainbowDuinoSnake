#include <Arduino.h>
#include <Game.h>

Game game;

void setup(){
    game.init();
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        int i = Serial.read();
        switch (i){
        case 'w':
            if(game.vec!=Point(0,speed)) game.vec = Point(0,-speed);
            break;

        case 's':
            if(game.vec!=Point(0,-speed)) game.vec = Point(0,speed);
            break;
        
        case 'd':
            if(game.vec!=Point(speed,0)) game.vec = Point(-speed,0);
            break;
        default:
            if(game.vec!=Point(-speed,0)) game.vec = Point(speed,0);
            break;
        }
    }
    game.pre_frame_time=millis();
    delay(25);
    uint64_t delta_time = millis()-game.pre_frame_time;
    game.update(static_cast<uint16_t>(delta_time),0);
    game.show();
}