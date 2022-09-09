//
//  SceneSettings.cpp
//  virtualShapes
//
//  Created by Patrick on 09.09.22.
//

#include "SceneSettings.hpp"


const string XML_SCENE_SETTINGS = "scenes.xml";

void SceneSettings::loadXML() {
    xml.load(XML_SCENE_SETTINGS);
    auto scenes = xml.getChild("scenes");
    if(!scenes){
        scenes = xml.appendChild("scenes");
    }
    
    auto sceneTimeoutNode = scenes.findFirst("sceneTimeout");
    sceneTimeout = sceneTimeoutNode.getIntValue();
}

//void SceneSettings::saveXML() {
//    xml.save(XML_SCENE_SETTINGS);
//}

