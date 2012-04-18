#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofEnableSmoothing();
    
    float myWidth = ofGetWidth()/2;
    float myHeight = ofGetHeight();
    ofPoint myPoint = *new ofPoint((float)0,-0.5);
    
    branch newBranch (ofPoint(myWidth,myHeight),myPoint,500.0);
    branches.push_back(newBranch);
    
}

//--------------------------------------------------------------
void testApp::update(){
     
    for (int i = branches.size()-1; i >= 0; i--) {
        branches[i].update();
        // If it's ready to split
        if (branches[i].timeToBranch()) {
            if (branches.size() < 1024) {
                branches.push_back(branches[i].brancher((float)30));   // Add one going right
                branches.push_back(branches[i].brancher((float)-30));   // Add one going left
                branches.push_back(branches[i].brancher(ofRandom(0,30)));   //Add one going in an somewhat random direction
            } 
            else {
                leaf newLeaf(branches[i].end);
                leaves.push_back(newLeaf);
            }
        }
    }

    cout << branches.size() << endl;
    cout << branches[0].timer << endl;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //don't worry if you see a blank screen for a second or two
    //the program is just working so give it a second to draw
    
    ofBackground(255);

    for (int i = branches.size()-1; i >= 0; i--) {
        branches[i].render();
    }
    
    for (int i = 0; i < leaves.size(); i++) {
        leaves[i].draw();
    }
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}