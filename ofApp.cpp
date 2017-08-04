#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofNoFill();

	this->max = 100;
	this->len_span = 10;

	for (int i = 0; i < this->max; i++) {
		this->log.push_back(ofVec3f(0, 0, 0));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	ofRotateX(90);

	float z = 0;
	Leap::Frame frame = leap.frame();
	for (Leap::Hand hand : frame.hands()) {
		if (hand.isRight()) {
			for (Leap::Finger finger : hand.fingers()) {
				if (finger.type() == Leap::Finger::Type::TYPE_INDEX) {
					z = finger.tipPosition().y + finger.direction().y * finger.length();
					z -= ofGetHeight() / 2;
					z *= -1;
				}
			}
		}
	}

	cout << "Z Point = " << z << endl;

	this->log.push_back(ofVec3f(0, 0, z));
	this->log.erase(this->log.begin());

	float alpha_span = 255 / max;

	for (float i = this->log.size() - 1; i > 0; i--) {
		ofSetColor(255, 255 - i * alpha_span);
		ofEllipse(this->log[this->log.size() - 1 - i], i * len_span, i * len_span);
	}

	this->cam.end();
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
