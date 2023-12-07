#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Setup webcam, plane and planeEffect
	webcam.setup(ofGetWidth(), ofGetHeight());
	planeEffect.setup(webcam.getTexture());
	plane.set(ofGetWidth(), ofGetHeight());


}

//--------------------------------------------------------------
void ofApp::update(){
	webcam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableAlphaBlending();
	ofEnableDepthTest();

	ofSetBackgroundColor(ofColor::black);
	
	// Start camera and draw effect
	cam.begin();
	planeEffect.draw(webcam.getTexture());
	cam.end();
	//cam.end();

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
