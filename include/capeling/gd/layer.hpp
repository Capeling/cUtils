#pragma once

namespace capeling::gd {
    template <typename... InitArgs>
    class Layer : public cocos2d::CCLayer {
    protected:
        cocos2d::CCSprite* m_backgroundSpr = nullptr;
        CCMenuItemSpriteExtra* m_backBtn = nullptr;
    protected:
        bool init(InitArgs ... args, char const* backBtnTex = "GJ_arrow_01_001.png") {
            if(!CCLayer::init())
                return false;

            auto director = cocos2d::CCDirector::get();
            auto winSize = director->getWinSize();

            m_backgroundSpr = geode::createLayerBG();
            addChild(m_backgroundSpr, -2);


            auto backBtnSpr = cocos2d::CCSprite::createWithSpriteFrameName(backBtnTex);
            m_backBtn = CCMenuItemSpriteExtra::create(backBtnSpr, this, menu_selector(Layer::onBack));

            auto backMenu = cocos2d::CCMenu::create();
            backMenu->setPosition(ccp(director->getScreenLeft() + 25.f, director->getScreenTop() - 22.f));
            backMenu->addChild(m_backBtn);
            addChild(backMenu);

            if(!setup(std::forward<InitArgs>(args)...))
                return false;

            setKeyboardEnabled(true);
            setKeypadEnabled(true);

            return true;
        }

        void keyBackClicked() override {
            this->onBack(nullptr);
        };

        virtual bool setup(InitArgs ... args) = 0;
        virtual void onBack(CCObject* sender) = 0;
    };
}