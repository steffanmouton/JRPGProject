#pragma once
#include "Application.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include <Renderer2D.h>


class JRPG : public aie::Application
{
public:
	JRPG();
	virtual ~JRPG();

	bool startup() override;
	void shutdown() override;

	void update(float deltaTime) override;
	void draw() override;

	

protected:

	aie::Renderer2D*	renderer;
	aie::Texture*		m_RathIdle;
	aie::Texture*		m_HunterSakuraIdle;
	aie::Texture*		m_HunterSakuraAttack; //Each frame 153 x 150
	aie::Texture*		m_HunterSakuraDying;
	aie::Texture*		m_HunterSakuraDead;
	aie::Texture*		m_CurPlayerAnimation;
	aie::Texture*		m_CurMonAnimation;
	aie::Font*			m_font;

	Entity* Sakura;
	Entity* Rathalos;

	enum pAnimate { pIdle, pAttack, pDead } pAn = pIdle;
	enum mAnimate { mIdle, mAttack, mDead } mAn = mIdle;

	int pAnCount = 0;
	int mAnCount = 0;

	float m_cameraX, m_cameraY;
	float m_timer;
};

