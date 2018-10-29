#pragma once
#include "Application.h"
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
	aie::Texture*		m_HunterSakura;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
};

