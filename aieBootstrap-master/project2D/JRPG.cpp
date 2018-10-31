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
	m_HunterSakuraIdle = new aie::Texture("./textures/HunterSakuraIdle1.png");
	m_HunterSakuraAttack = new aie::Texture("./textures/HunterSakuraAttackAnimation.png");
	m_HunterSakuraDying = new aie::Texture("./textures/HunterSakuraDying.png");
	m_HunterSakuraDead = new aie::Texture("./textures/HunterSakuraDead.png");
	m_CurMonAnimation = m_RathIdle;
	m_CurPlayerAnimation = m_HunterSakuraIdle;


	m_font = new aie::Font("./font/consolas.ttf", 32);

	Sakura = new Player{ 100, 30, 10};
	Rathalos = new Monster{ 300, 20, 1};
	Sakura->SetTarget(Rathalos);
	Rathalos->SetTarget(Sakura);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	

	return true;
}

void JRPG::shutdown()
{
	delete m_font;
	delete m_RathIdle;
	delete m_HunterSakuraIdle;
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

float drawTimer;
float startTime;

void JRPG::draw()
{
	
	//Menu
	ImGui::BeginMenu("Battle");
	if (ImGui::Button("Attack", ImVec2(100, 50)))
	{
		Sakura->Attack();
		Rathalos->Attack();
		pAn = pAttack;

	}
	if (ImGui::Button("Items", ImVec2(100, 50)))
	{
		
	}
	if (ImGui::Button("Guard", ImVec2(100, 50)))
	{

	}
	if (ImGui::Button("Flee", ImVec2(100, 50)))
	{

	}

	if (Sakura->isAlive() != true)
	{
		pAn = pDead;
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
	//renderer->setUVRect(int(m_timer * 7) % 4 / 4.0f, 0, 1.f / 4, 1.f);
	//
	//renderer->drawSprite(m_CurPlayerAnimation, 400, 600, 222, 144, 0, 1, 0, 0);

	//animate player attack
	/*renderer->setUVRect(int(m_timer * 8) % 27 / 27.0f, 150, 1.f / 27, 1.f);
	renderer->drawSprite(m_HunterSakuraAttack, 400, 300, 153, 155, 0, 1, 0, 0);*/
	
	switch (pAn)
	{
	case pIdle:
		m_CurPlayerAnimation = m_HunterSakuraIdle;
		renderer->setUVRect(int(m_timer * 8) % 4 / 4.0f, 0, 1.f / 4, 1.f);
		
		break;

	case pAttack:
		m_CurPlayerAnimation = m_HunterSakuraAttack;
		renderer->setUVRect(int(m_timer * 8) % 27 / 27.0f, 150, 1.f / 27, 1.f);
		startTime = m_timer;
		drawTimer += (m_timer - startTime);
		

		if (drawTimer >= 400.f)
		{
			startTime = 0;
			drawTimer = 0;
			pAn = pIdle;
		}
		break;

	case pDead:
		m_CurPlayerAnimation = m_HunterSakuraDying;
		renderer->setUVRect(0, 0, 1, 1);

		if (pAnCount == 10)
		{
			m_CurPlayerAnimation = m_HunterSakuraDead;
		}
	
		break;
	}
	////draw monster
	//renderer->setUVRect(0, 0, 1, 1);
	//renderer->drawSprite(m_Rath, 1200, 400, 0, 0, 0, 1, 0, 0);

	renderer->drawSprite(m_CurPlayerAnimation, 400, 600, 222, 144, 0, 1, 0, 0);

	//animate monster
	renderer->setUVRect(int(m_timer * 8) % 14 / 14.0f, 0, 1.f / 14, 1.f);

	renderer->drawSprite(m_CurMonAnimation, 1000, 535, 846, 546, 0, 1, 0, 0);

	//show hp
	char pHp[32];
	sprintf_s(pHp, 32, "%i", Sakura->getHp());
	renderer->drawText(m_font, pHp, 450, 600);
	char mHp[32];
	sprintf_s(mHp, 32, "%i", Rathalos->getHp());
	renderer->drawText(m_font, mHp, 1000, 600);

	if (Sakura->isAlive() != true)
	{
		char deadText[32];
		sprintf_s(deadText, 32, "YOU DIED");
		renderer->drawText(m_font, deadText, 600, 600);
	}


	renderer->end();
}
