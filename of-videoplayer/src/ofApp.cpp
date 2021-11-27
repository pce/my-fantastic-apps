#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // xml
    if (!xml.load("settings.xml")) {
        ofLogError() << "Could not load settings.xml";
    }
    
    auto hasSettings = xml.getChild("settings");
    if (!hasSettings) {
        auto settings = xml.appendChild("settings");
        settings.appendChild("logo").set("images/loco.png");
        settings.appendChild("font").set("fonts/SFNS.ttf");
        settings.appendChild("smallfont").set("fonts/SFNS.ttf");
        auto videopath = settings.appendChild("videos");
        videopath.appendChild("video").setAttribute("path", "videos/unreal-still_life.mp4");
        videopath.appendChild("video").setAttribute("path", "videos/unreal-niagaraboxes.mp4");
        
        videopath.appendChild("video").setAttribute("path", "videos/of-particles.mp4");

        if(!xml.save("settings.xml")){
            ofLogError() << "Couldn't save settings.xml";
        }
    }
    auto logo = xml.findFirst("/settings/logo").getValue();
    auto fontPath = xml.findFirst("/settings/font").getValue();
    auto smallfontPath = xml.findFirst("/settings/smallfont").getValue();
    
    // font
    font.load(fontPath, 42, true, true);
    smallfont.load(smallfontPath, 21, true, true);
    // images
    logoImage.load(logo);
    // osc
    receiver.setup(OSC_PORT);
    // preload videos 
    // for videos load:
    auto videosXml = xml.find("//videos/video");
    int i=0;
    videoPlayers.resize(videosXml.size());
	for(auto & video: videosXml) {
        videoPlayers.at(i).load(video.getAttribute("path").getValue());
        i++;
    }
    videoPlayers.at(curmovie).play();
    
    // sender.setup("0.0.0.0", 12346);
    sender.setup("localhost", 12346);
}

//--------------------------------------------------------------
void ofApp::update(){
    // osc receive video number
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        // select and play video
        if (m.getAddress() == "/video/n") {
          movienum = m.getArgAsInt32(0);
          if (movienum != curmovie && movienum <= videoPlayers.size()-1) {
            videoPlayers.at(curmovie).stop();
            curmovie = movienum;
            videoPlayers.at(curmovie).play();
          }
        }

        // ATM Unused: set pos by percent 0-100
        if (m.getAddress() == "/video/pos") {
          int percent = m.getArgAsInt32(0);
          if (percent > 100) percent = 100;
          if (percent < 0) percent = 0;
          float pct = static_cast<float>(percent) / 100;
          videoPlayers.at(curmovie).setPosition(pct);
        }
    }
    // video
    videoPlayers.at(curmovie).update();
    
    // osc send stats
    ofxOscMessage m;
    m.setAddress( "/stats" );
    m.addFloatArg(videoPlayers.at(curmovie).getDuration());
    m.addFloatArg(videoPlayers.at(curmovie).getPosition());
    sender.sendMessage( m );
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofRectangle screenRect(0, 0, ofGetWidth(), ofGetHeight());
    ofRectangle videoRect(0, 0,
      videoPlayers.at(curmovie).getWidth(), videoPlayers.at(curmovie).getHeight()
    );
    ofRectangle videoFullscreenRect = videoRect;
    videoFullscreenRect.scaleTo(screenRect, OF_ASPECT_RATIO_KEEP_BY_EXPANDING);
    videoPlayers.at(curmovie).draw(videoFullscreenRect);
    // if (curmovie != 2 || curmovie != 3)
    ofEnableAlphaBlending();
    // logo
    logoImage.draw(10,10);

    if (curmovie == videoPlayers.size()-1) {
        ofEnableAlphaBlending();
        ofSetColor(255,196,126,127); // 50% transparent
        // ofDrawRectangle(0, ofGetHeight() / 2 + 20, ofGetWidth(), ofGetHeight() / 2);
        font.drawString(
            "Sea of Tranquility orange dwarf \n\
                    ... stirred by starlight",
            (ofGetWidth() / 2 - 350), (ofGetHeight() / 2 + 120)
        );

        smallfont.drawString(
            "how far away another world are creatures of the cosmos intelligent beings? \n",
            (ofGetWidth() / 2 - 480), (ofGetHeight() / 2 + 270)
        );
    }
    ofDisableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    // demo: any key sets to a fixed position
    float pct = 0.5;
    videoPlayers.at(curmovie).setPosition(pct);
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
    // demo: mouse click to play next video
    videoPlayers.at(curmovie).stop();
    curmovie = (curmovie >= videoPlayers.size()-1) ? 0 : ++curmovie;
    videoPlayers.at(curmovie).play();
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
