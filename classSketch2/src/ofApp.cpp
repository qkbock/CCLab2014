#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    for(int i=0; i <5; i++){
        Ball ball;
        ball.setup(ofRandomWidth(), ofRandomHeight());
        ballVector.push_back(ball);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i < ballVector.size(); i++){
        ballVector[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i < ballVector.size(); i++){
        ballVector[i].display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_DOWN:
            if (ballVector.size() > 0) {
                for(int i =0; i < 5; i++){
                    ballVector.erase(ballVector.begin());
                }
            }
            break;
            
        default:
            break;
    }
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
    for(int i=0; i < 500; i++){
        Ball ball;
        ball.setup(x, y);
        ballVector.push_back(ball);
    }
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
