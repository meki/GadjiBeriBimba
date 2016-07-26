#include "ofApp.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream fs;

std::vector<ofColor> colors;

//--------------------------------------------------------------
void ofApp::setup(){

	// ofSetFullscreen(true);

	colors = {
		ofColor::antiqueWhite
		,ofColor::aliceBlue
		,ofColor::chocolate
		,ofColor::darkRed
		,ofColor::darkSlateGray
		,ofColor::mediumOrchid
		,ofColor::lightSkyBlue
		,ofColor::navy
		,ofColor::purple
		,ofColor::pink
		,ofColor::coral
		,ofColor::darkGoldenRod
		,ofColor::ivory
		,ofColor::olive
		,ofColor::limeGreen
		,ofColor::silver
		,ofColor::orange
		,ofColor::brown
		,ofColor::forestGreen
		,ofColor::lightCyan
		,ofColor::salmon
		,ofColor::violet
		,ofColor::midnightBlue
		,ofColor::gold
		,ofColor::black
		,ofColor::tomato
	};

	//fs.open("score.txt");
	fs.open(R"(C:\Users\Satoshi\Documents\of_v0.9.0\projects\GadjiBeriBimba\score.txt)", ios::in);

	if (fs.fail())
	{
		cout << "file load error" << endl;
		abort();
	}
}

const ofColor CLEAR = ofColor(255, 255, 255);

ofColor dispColor = CLEAR;

string line;
string::iterator sit = line.end();

//--------------------------------------------------------------
void ofApp::update()
{
	static uint64_t waitTime = 0;
	static uint64_t prevTime = 0;
	auto currTime = ofGetElapsedTimeMillis();
	auto interval = currTime - prevTime;

	if (interval > waitTime)
	{
		if (sit == line.end())
		{
			if (fs.eof())
			{
				return;
			}

			getline(fs, line);
			sit = line.begin();
			// dispColor = CLEAR;
			waitTime = 600;
			prevTime = currTime;
			return;
		}

		char c = *sit;
		if (c == ' ')
		{
			// dispColor = CLEAR;
			waitTime = 300;
		}
		else
		{
			int idx = c - 'a';
			dispColor = colors[idx];
			waitTime = 120;
		}

		++sit;
		prevTime = currTime;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofClear(dispColor);

	//ofSetColor(dispColor);
	//ofDrawEllipse(100, 100, 250, 250);
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
