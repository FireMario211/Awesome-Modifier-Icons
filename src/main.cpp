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
		
		CCSprite* newSpr = CCSprite::createWithSpriteFrameName("edit_eCollisionBlock01_001.png");
		setTexture(newSpr->getTexture());
		setTextureRect(newSpr->getTextureRect());

		queueInMainThread([this, texture]() {
			
			if (CCLabelBMFont* label = getChildOfType<CCLabelBMFont>(this, 0)) {
				label->setVisible(false);
			}

			auto spr = CCSprite::create(texture.c_str());
			spr->setScale(0.9f);
			addChildAtPosition(spr, Anchor::Center);
		});
	}
};