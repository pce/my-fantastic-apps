//
//  SceneSettings.hpp
//  virtualShapes
//
//  Created by Patrick on 09.09.22.
//

#ifndef SceneSettings_hpp
#define SceneSettings_hpp

#include "ofMain.h"

class SceneSettings {
public:
    void loadXML();
    int sceneTimeout{10};
private:
    ofXml xml;
};

#endif /* SceneSettings_hpp */
