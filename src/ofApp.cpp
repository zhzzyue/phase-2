#include "ofApp.h"

vector<leaf> leaves;

//ofPoint t;
//ofPoint p0, p1;
//ofFbo fbo;

leaf::leaf(){
//    leafImg.load("leaf.png");
    
    // while(!leafImg.getWidth());  // loop here till loaded
//    loc -= ofPoint(0,0,0);
//    sTime = ofGetElapsedTimef();
//    sWeight = ofRandom(0.1, 0.4);
//    fallSpeed = ofRandom(2, 8);
}

void leaf::setup(){

    loc += ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    sTime = ofRandom(0.1,2);
    sWeight = ofRandom(1, 1.5);
//    fallSpeed = ofRandom(2, 8);
    
//    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    a=ofRandom(0.2,0.3);
    b=ofRandom(0.3,0.4);
    c=ofRandom(0.4,0.5);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));

    
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    
//    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
//    fbo.begin();
//    ofSetColor(255,255,255, alpha);
//    ofDrawRectangle(0,0,400,400);
//    fbo.end();
//    
    ofSetBackgroundColor(0,0,0);



}

void leaf::update(){
    float time = sTime*ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5) * 200.0;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.6) * 200.0;
    rZ = ofSignedNoise(time * 0.7) * 200.0;
    dScale = (1 - ofNoise(time * 0.2)) * sWeight;
    //dScaleX = (1 - ofNoise(time * 0.2)) * sWeight;
    //dScaleY = (1 - ofNoise(time * 0.4)) * sWeight;
    //dScaleZ = (1 - ofNoise(time * 0.6)) * sWeight;
    
    moveX= ofSignedNoise(time*a)*ofRandom(1,20);
    moveY= ofSignedNoise(time*b)*ofRandom(1,20);
    moveZ= ofSignedNoise(time*c)*ofRandom(1,20);
    
    loc += ofPoint(moveX, moveY, moveZ);
    
    
//        fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
//        fbo.begin();
//        ofClear(255,255,255,0);
//        fbo.end();

}

void leaf::draw() {
//    ofPushMatrix();
//    float z = ofSignedNoise((ofGetElapsedTimef() + sTime) * 0.9) * 400;
//    ofTranslate(loc.x, loc.y, z);
//    // ofScale(dScaleX, dScaleY, dScaleZ);  // can be 3 dimensional
//    ofScale(dScale, dScale, dScale);
//    ofRotateX(rX);
//    ofRotateY(rY);
//    ofRotateZ(rZ);
//    ofPopMatrix();

//    ofBackground(255);
    fbo.begin();
    cout<<"hello world!"<<endl;
//    ofPushStyle();
    ofSetColor(255,255,255, 10);  // alpha fade it
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    
    ofDrawLine(-40, 0, 40, 0);
    ofDrawLine(40, 0, 0, 40);
    ofDrawLine(0, 40, -40, 0);
//    ofDrawCircle(150,150,20);
//    ofSetColor(color);
//    ofFill();
//    ofDrawSphere(ofGetWidth() * .1, ofGetHeight()* .1, 10);
    ofPopStyle();
    ofPopMatrix();
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
    
}

//ofTrueTypeFont title;
//ofImage bg;



//--------------------------------------------------------------
void ofApp::setup(){
//    p0 = ofPoint(-20, 0);
//    p1 = ofPoint( 20, 0);
    
//    t = ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0);
//    
//    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
//    
//    fbo.begin();
//    ofClear(255,255,255, 0);
//    fbo.end();
//    
//    ofSetBackgroundColor(0);
    
    for(int i=0; i<5; i++){
        leaf newleaf;
        newleaf.setup();
        leaves.push_back(newleaf);
        
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
//    float time = ofGetElapsedTimef();
//    
//    rX = ofSignedNoise(time * 0.5) * 200.0;
//    rY = ofSignedNoise(time * 0.3) * 200.0;
//    rZ = ofSignedNoise(time * 0.9) * 200.0;
//    
//    
//    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
//    float y = ofMap(ofSignedNoise(time * 0.4), -1, 1, 0, ofGetHeight());
//    float z = ofMap(ofSignedNoise(time * 0.6), -1, 1, -1500, 1500);
//    
//    t = ofPoint(x, y, z);
    
    for(int i=0; i<leaves.size(); i++){
        leaves[i].update();
        cout << "my Point [" << i << "]: " << leaves[i].loc <<endl;
        
        
        if(leaves[i].loc.y<0||leaves[i].loc.y>ofGetWindowHeight()||leaves[i].loc.x<0||leaves[i].loc.x>ofGetWindowWidth()){
            leaves.erase(leaves.begin()+i);
            leaf newleaf;
            newleaf.setup();
            leaves.push_back(newleaf);
        }
    }

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    fbo.begin();
//    ofPushStyle();
//    ofSetColor(0,0,0,1);  // alpha fade it
//    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//    ofPopStyle();
//    
//    ofPushMatrix();
//    ofTranslate(t);
//    
//    ofRotateX(rX);
//    ofRotateY(rY);
//    ofRotateZ(rZ);
//    
//    ofPushStyle();
//    ofSetColor(80, 200, 120, 180);
//    ofDrawLine(p0, p1);
//    ofPopStyle();
//    ofPopMatrix();
//    fbo.end();
//    
//    fbo.draw(0,0);
    
    for(int i=0; i<leaves.size(); i++){
        leaves[i].draw();
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
