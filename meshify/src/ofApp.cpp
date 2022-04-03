#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // image.load("richard-horvath-WOA3QKFjlo8-unsplash.jpg");
    image.load("darius-bashar-WygY5SFLQiE-unsplash.jpg");
    
    // TODO aspect ratio resize ( 1024,768 )
    // 2500 × 1667
    // image.resize(ofGetWidth(), ofGetHeight());
    // image.resize(ofGetWidth()*.5, ofGetHeight()*.5);
    image.resize(1024*.25, 768*.25);

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
    generateMesh();
    
    // gui
    gui.setup("panel");
    intensityThreshold.addListener(this, &ofApp::intensityThresholdChange);
    gui.add(intensityThreshold.set("intensityThreshold", 150.0f,1,300));
    gui.add(meshVerticesCount.set(mesh.getNumVertices()));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // mesh
    // meshVerticesCount.set(mesh.getNumVertices());

}


//--------------------------------------------------------------
void ofApp::intensityThresholdChange(float &f){
    intensityThreshold = f;
    generateMesh();
}


//--------------------------------------------------------------
void ofApp::generateMesh(){
    int w = image.getWidth();
    int h = image.getHeight();
    
    mesh.clear();
    
    for(int x=0; x<w-1; x++){
        for(int y=0; y<h-1; y++){
            ofColor c = image.getColor(x, y);
            // or brighness?
            float intensity = c.getLightness();
            if(intensity>=intensityThreshold){
                ofVec3f pos(x*4, y*4, .0);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofBackground(0, 0, 0);
    ofBackgroundGradient(ofColor(0,0,0), ofColor(0,128,255));
    // image.draw(0,0);
    mesh.draw();
    
    if(bShowGui){
        gui.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'd':
            bShowGui = !bShowGui;
        break;
    }

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
