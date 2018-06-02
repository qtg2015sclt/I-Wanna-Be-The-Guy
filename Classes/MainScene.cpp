//
//  MainScene.cpp
//  IWannaBeTheGuy
//
//  Created by qutiange on 2018/6/2.
//
//

#include "MainScene.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainScene::create();
    scene->addChild(layer);
    return scene;
}

// Log
static void problemLoading(const char* fileName)
{
    printf("Cannot load %s", fileName);
}

// Constants
struct Constants {
    const char* kidName = "kid";
    const char* mikuBossName = "mikuBoss";
    const char* kidResourceName = "kid-01.png";
    const char* mikuBossResourceName = "miku-01.jpeg";
    
    const EventKeyboard::KeyCode keyLeftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
    const EventKeyboard::KeyCode keyRightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
    const EventKeyboard::KeyCode keyLeftShift = EventKeyboard::KeyCode::KEY_LEFT_SHIFT;
    
    const int horizontalOffset = 2;
} Constants;

bool MainScene::init()
{
    if ( !LayerColor::init() ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    this->initWithColor(Color4B::WHITE);
    
    mikuBoss = Sprite::create(Constants.mikuBossResourceName);
    if (nullptr == mikuBoss) {
        problemLoading(Constants.mikuBossResourceName);
    }
    else {
        mikuBoss->setAnchorPoint(Vec2(1, 0));
        mikuBoss->setScale(0.4);
        mikuBoss->setPosition(visibleSize.width, 0);
        this->addChild(mikuBoss);
    }
    
    kid = Sprite::create(Constants.kidResourceName);
    if (nullptr == kid) {
        problemLoading(Constants.kidResourceName);
    }
    else {
        kid->setAnchorPoint(Vec2(0, 0));
        kid->setScale(0.03);
        kid->setPosition(0, 0);
        this->addChild(kid);
    }
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MainScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MainScene::onKeyReleased, this);
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, kid);
    
    this->scheduleUpdate();
    
    return true;
}

void MainScene::update(float delta)
{
    Node::update(delta);
    
    
    if (isKeyPressed(Constants.keyLeftShift)) {
        keyPressedAction(Constants.keyLeftShift);
    }
    
    if (isKeyPressed(Constants.keyRightArrow)) {
        keyPressedAction(Constants.keyRightArrow);
    } else if (isKeyPressed(Constants.keyLeftArrow)) {
        keyPressedAction(Constants.keyLeftArrow);
    }
}

void MainScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    keysPressed[keyCode] = true;
}

void MainScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    keysPressed[keyCode] = false;
}

bool MainScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
    if (keysPressed[keyCode]) {
        return true;
    }
    else {
        return false;
    }
}

void MainScene::keyPressedAction(EventKeyboard::KeyCode keyCode)
{
    int offsetX = 0;
    int offsetY = 0;
    
    if (EventKeyboard::KeyCode::KEY_LEFT_SHIFT == keyCode) {
        ;
    }
    
    if (EventKeyboard::KeyCode::KEY_LEFT_ARROW == keyCode) {
        offsetX = -Constants.horizontalOffset;
    } else if (EventKeyboard::KeyCode::KEY_RIGHT_ARROW == keyCode) {
        offsetX = Constants.horizontalOffset;
    }
    
    MoveBy* move = MoveBy::create(0.3, Vec2(offsetX, offsetY));
    kid->runAction(move);
}
