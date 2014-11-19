#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vidGrabber.initGrabber(320, 240);
finder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()) {
        finder.findHaarObjects(vidGrabber.getPixelsRef());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    vidGrabber.draw(0, 0, 640, 480);
    ofNoFill();
    for (unsigned int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle face = finder.blobs[i].boundingRect;
        ofRect(face.x*2, face.y*2, face.width*2, face.height*2);
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
