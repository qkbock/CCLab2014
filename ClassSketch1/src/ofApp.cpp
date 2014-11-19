#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetCircleResolution(60);
    ofEnableSmoothing();
    ofNoFill();
    ofSetBackgroundAuto(false);
    
    circleSize = 0;
    
    myColors[0] = ofColor::pink;
    myColors[1] = ofColor::green;
    myColors[2] = ofColor::blue;
    myColors[3] = ofColor::aquamarine;
    myColors[4] = ofColor::yellowGreen;
    
    showCoor = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            ofSetColor(myColors[0]);
            break;
        case '2':
            ofSetColor(myColors[1]);
            break;
        case '3':
            ofSetColor(myColors[2]);
            break;
        case '4':
            ofSetColor(myColors[3]);
            break;
        case '5':
            ofSetColor(myColors[4]);
            break;
        case 'r':
            ofBackground(0);
            ofSetColor(255);
            break;
        case 's':
            showCoor =! showCoor;
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    string ourMouseXPos = ofToString(x);
    string ourMouseYPos = ofToString(y);
    
    string ourDebugString = "x: " + ourMouseXPos + "\n" + "y: " + ourMouseYPos;
    
    if(showCoor){
        ofBackground(0);
        ofDrawBitmapString(ourDebugString, x+10, y-10);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    circleSize++;
    ofCircle(x, y, circleSize);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    circleSize = 0;
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
