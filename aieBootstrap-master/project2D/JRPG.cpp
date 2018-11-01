#include "JRPG.h"



JRPG::JRPG()
{
}


JRPG::~JRPG()
{
}

bool JRPG::startup()
{
	//loading renderer
	renderer = new aie::Renderer2D();

	//loading font
	m_font = new aie::Font("./font/consolas.ttf", 32);

	//loading Rathalos animations and target
	Rathalos = new Monster{ 300, 20, 1 };
	m_RathIdle = new aie::Texture("./textures/RathIdleAnimation.png");
	Rathalos->m_CurTexture = m_RathIdle;
	Rathalos->SetTarget(Sakura);

	//loading hunter Sakura animations and target
	Sakura = new Player{ 100, 30, 10 };
	m_HunterSakuraIdle = new aie::Texture("./textures/HunterSakuraIdle1.png");
	m_HunterSakuraAttack = new aie::Texture("./textures/HunterSakuraAttackAnimation.png");
	m_HunterSakuraDying = new aie::Texture("./textures/HunterSakuraDying.png");
	m_HunterSakuraDead = new aie::Texture("./textures/HunterSakuraDead.png");
	Sakura->textures = {m_HunterSakuraAttack, m_HunterSakuraDead, m_HunterSakuraDying, m_HunterSakuraIdle };
	// TODO: Make UVRects squares and vectors : Sakura->uvRects = {}
	Sakura->m_CurTexture = m_HunterSakuraIdle;
	Sakura->SetTarget(Rathalos);

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
	delete Sakura;
	
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
}

float drawTimer;
float startTime;

void JRPG::draw()
{
	
	//Menu
	ImGui::BeginMenu("Battle");
	if (ImGui::Button("Attack", ImVec2(100, 50)))
	{
		Sakura->eState = Entity::EntityState::Attacking;

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


	//wipe screen to default color
	clearScreen();

	//default camera pos
	renderer->setCameraPos(m_cameraX, m_cameraY);

	//begin drawing sprites
	renderer->begin();

	////draw player
	Sakura->eDraw(renderer, Sakura->m_CurUV);
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
	
	/*switch (pAn)
	{
	case pIdle:
		m_CurPlayerAnimation = m_HunterSakuraIdle;
		renderer->setUVRect(int(m_timer * 8) % 4 / 4.0f, 0, 1.f / 4, 1.f);
		
		break;

	case pAttack:
		
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
	}*/
	////draw monster
	//renderer->setUVRect(0, 0, 1, 1);
	//renderer->drawSprite(m_Rath, 1200, 400, 0, 0, 0, 1, 0, 0);

	renderer->drawSprite(m_CurPlayerAnimation, 400, 600, 222, 144, 0, 1, 0, 0);

	//animate monster
	renderer->setUVRect(int(m_timer * 8) % 14 / 14.0f, 0, 1.f / 14, 1.f);

	//846 x 546
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
