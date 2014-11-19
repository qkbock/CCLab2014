//
//  Walrus.h
//  Wal
//
//  Created by Quincy Bock on 11/6/14.
//
//

#pragma once
#include "ofMain.h"

class Ball{
public:
    
    ofVec2f pos;
    ofVec2f vel;
    
    ofColor color;
    
    void setup(float _x, float _y);
    void move();
    void display();
};


