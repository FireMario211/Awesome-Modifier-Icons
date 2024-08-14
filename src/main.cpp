#include <Geode/Geode.hpp>
#include <Geode/modify/EffectGameObject.hpp>

using namespace geode::prelude;

class $modify(MyEffectGameObject, EffectGameObject) {

	void customSetup() {
		EffectGameObject::customSetup();

		switch(m_objectID){

			case 1755: {
				setIcon("d_block.png"_spr);
				break;
			}
			case 1813: {
				setIcon("j_block.png"_spr);
				break;
			}
			case 1829: {
				setIcon("s_block.png"_spr);
				break;
			}
			case 1859: {
				setIcon("h_block.png"_spr);
				break;
			}
			case 2866: {
				setIcon("f_block.png"_spr);
				break;
			}
		}
	}

	void setIcon(std::string texture){
		
		if (!Mod::get()->getSettingValue<bool>("solid-border")) {
			if(CCSprite* newSpr = CCSprite::createWithSpriteFrameName("edit_eCollisionBlock01_001.png")) {
				setTexture(newSpr->getTexture());
				setTextureRect(newSpr->getTextureRect());
			}
			else{
				log::info("missing collision block sprite");
			}
		}
		
		setCascadeColorEnabled(true);
		setCascadeOpacityEnabled(true);

		if(auto spr = CCSprite::create(texture.c_str())) {
			spr->setScale(0.9f);
			addChildAtPosition(spr, Anchor::Center);
			
			scheduleOnce(schedule_selector(MyEffectGameObject::getLabel), 0);
		}
		else{
			log::info("missing modifier sprite");
		}
		
	}

	void getLabel(float dt){

		if (CCLabelBMFont* label = getChildOfType<CCLabelBMFont>(this, 0)) {
			if (Mod::get()->getSettingValue<bool>("show-letter")) {
				label->setPosition({2, getContentHeight()});
				label->setScale(0.3f);
				label->setAnchorPoint({0, 1});
			}
			else {
				label->setVisible(false);
			}
		}
	}
};