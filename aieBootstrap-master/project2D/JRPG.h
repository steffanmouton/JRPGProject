#pragma once
#include "Application.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <iostream>
#include <Renderer2D.h>


class JRPG : public aie::Application
{
public:
	JRPG();
	virtual ~JRPG();

	bool startup() override;
	void shutdown() override;

	void update(float dt) override;
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

	float m_cameraX, m_cameraY;
	float m_timer;
};

