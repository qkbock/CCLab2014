#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    distance = 100.0;
    //  by default, openFrameworks does calculations using RADIANS, not degrees.
    //  The unit circle's circumference is TWO_PI,
    //  which is a pre-defined constant.
    //  (Hold command and click "TWO_PI" if you're curious to see where this is defined).
    increment = TWO_PI / NUMCIRCS;
    
    offsetX = ofGetWindowWidth() / 2;
    offsetY = ofGetWindowHeight() / 2;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //  add a pulse to the radius
    distance = cos(ofGetElapsedTimef() * 3.0) * 250;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //  we'll be drawing the number of circles we set at the beginning
    //  where we defined the constant NUMCIRCS
    
    for (int i = 0; i < NUMCIRCS; i++) {
        
        // first set the color using HSB
        ofColor color;
        float hue = ofMap(i, 0, NUMCIRCS, 0, 255);
        color.setHsb(hue, 255, 255);
        ofSetColor(color);
        
        //  then determine what the angle is for particular circle
        
        float angle = increment * i;
        float posX = (cos(angle) * distance) + offsetX;
        float posY = (sin(angle) * distance) + offsetY;
        
        //  uncomment the next two lines to make the circles go around the mouse
        //offsetX = mouseX;
        //offsetY = mouseY;
        
        ofCircle(posX, posY, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
