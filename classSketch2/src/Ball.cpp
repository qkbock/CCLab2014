//
//  Ball.cpp
//  classSketch2
//
//  Created by Quincy Bock on 11/13/14.
//
//

#include "Ball.h"

void Ball::setup(float _x, float _y){
    
    pos.set(_x, _y);
    
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
    vel.x = ofRandom(-5, 5);
    vel.y = ofRandom(-5, 5);
}

void Ball::move(){
    
    pos += vel;
    
    if(pos.x >= ofGetWindowWidth()){
        pos.x = ofGetWindowWidth();
        vel.x *= -1;
    }
    if(pos.x <= 0){
        pos.x = 0;
        vel.x *= -1;
    }
    if(pos.y >= ofGetWindowHeight()){
        pos.y = ofGetWindowHeight();
        vel.y *= -1;
    }
    if(pos.y <= 0){
        pos.y = 0;
        vel.y *= -1;
    }
}

void Ball::display(){
    ofSetColor(color);
    ofCircle(pos.x, pos.y, 10);
}