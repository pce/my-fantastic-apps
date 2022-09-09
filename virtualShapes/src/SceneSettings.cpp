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
    
}

