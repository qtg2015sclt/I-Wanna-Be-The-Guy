//
//  MainScene.hpp
//  IWannaBeTheGuy
//
//  Created by qutiange on 2018/6/2.
//
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>

class MainScene: public cocos2d::LayerColor{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void update(float delta);
    
    CREATE_FUNC(MainScene);
private:
    cocos2d::Sprite* kid;
    cocos2d::Sprite* mikuBoss;
    std::map<cocos2d::EventKeyboard::KeyCode, bool> keysPressed;
    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
    void keyPressedAction(cocos2d::EventKeyboard::KeyCode keyCode);
};

#endif /* MainScene_hpp */
