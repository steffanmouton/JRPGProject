#include "JRPG.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <iostream>


JRPG::JRPG()
{
}


JRPG::~JRPG()
{
}

bool JRPG::startup()
{

	renderer = new aie::Renderer2D();

	m_RathIdle = new aie::Texture("./textures/RathIdleAnimation.png");
	m_HunterSakura = new aie::Texture("./textures/HunterSakuraIdle1.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void JRPG::shutdown()
{
	delete m_font;
	delete m_RathIdle;
	delete m_HunterSakura;
	delete renderer;
}

void JRPG::update(float deltaTime)
{
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
	//Move Player
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{

	}
}

void JRPG::draw()
{

	//
	ImGui::BeginMenu("Battle");
	if (ImGui::Button("Attack", ImVec2(200, 200)))
	{

	}
	


	//wipe screen to default color
	clearScreen();

	//default camera pos
	renderer->setCameraPos(m_cameraX, m_cameraY);

	//begin drawing sprites
	renderer->begin();

	////draw player
	//renderer->setUVRect(0, 0, 1, 1);
	//renderer->drawSprite(m_HunterSakura, 600, 400, 0, 0, 0, 1, 0, 0);

	//animate player idle
	//setUVRect(int(m_timer) % "# of cycles" / "#cycles", "% current in y", "RectWidth", "RectHeight") 
	renderer->setUVRect(int(m_timer * 3) % 4 / 4.0f, 0, 1.f / 4, 1.f);
	
	renderer->drawSprite(m_HunterSakura, 400, 600, 222, 144, 0, 1, 0, 0);

	////draw monster
	//renderer->setUVRect(0, 0, 1, 1);
	//renderer->drawSprite(m_Rath, 1200, 400, 0, 0, 0, 1, 0, 0);

	//animate monster
	renderer->setUVRect(int(m_timer * 8) % 14 / 14.0f, 0, 1.f / 14, 1.f);

	renderer->drawSprite(m_RathIdle, 1000, 535, 846, 546, 0, 1, 0, 0);



	renderer->end();
}
