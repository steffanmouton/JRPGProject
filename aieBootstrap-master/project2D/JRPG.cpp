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
	m_MonsterPos = { 1200, 600 };
	MonsterChar = new Monster{ 300, 100, 10, m_MonsterPos, "Rathalos" };
	m_MonsterIdle = new aie::Texture("./textures/RathIdleAnimation.png");
	m_MonsterIdleUV = new Rect(14, 1.f, 7, 846, 546);

	MonsterChar->textures = { m_MonsterIdle };
	MonsterChar->uvRects = { m_MonsterIdleUV };

	MonsterChar->m_CurTexture = MonsterChar->textures[0];
	MonsterChar->m_CurUV = MonsterChar->uvRects[0];

	//loading hunter Sakura animations and target
	m_PlayerPos = { 400, 600 };
	PlayerChar = new Player{ 100, 30, 10, m_PlayerPos, "Sakura" };
	m_PlayerIdle = new aie::Texture("./textures/HunterSakuraIdle1.png");
	m_PlayerIdleUV = new Rect(4, 1.f, 7, 153, 150);
	m_PlayerAttack = new aie::Texture("./textures/HunterSakuraAttackAnimation.png");
	m_PlayerAttackUV = new Rect(27, 1.f, 7, 153, 150);
	m_PlayerDying = new aie::Texture("./textures/HunterSakuraDying.png");
	m_PlayerDyingUV = new Rect(1, 1.f, 7, 153, 150);
	m_PlayerDead = new aie::Texture("./textures/HunterSakuraDead.png");
	m_PlayerDeadUV = new Rect(1, 1.f, 7, 153, 150);

	PlayerChar->textures = {m_PlayerIdle, m_PlayerAttack, m_PlayerDying, m_PlayerDead };
	PlayerChar->uvRects = { m_PlayerIdleUV, m_PlayerAttackUV, m_PlayerDyingUV, m_PlayerDeadUV };

	PlayerChar->m_CurTexture = PlayerChar->textures[0];
	PlayerChar->m_CurUV = PlayerChar->uvRects[0];
	PlayerChar->SetTarget(MonsterChar);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void JRPG::shutdown()
{
	delete m_font;
	delete MonsterChar;
	delete m_MonsterIdleUV;
	delete PlayerChar;
	delete m_PlayerIdle;
	delete m_PlayerIdleUV;
	delete m_PlayerAttack;
	delete m_PlayerAttackUV;
	delete m_PlayerDying;
	delete m_PlayerDyingUV;
	delete m_PlayerDead;
	delete m_PlayerDeadUV;
	delete renderer;
	
	
}

void JRPG::update(float deltaTime)
{
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	PlayerChar->eUpdate(deltaTime);
	MonsterChar->eUpdate(deltaTime);

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


void JRPG::draw()
{
	//wipe screen to default color
	clearScreen();

	//default camera pos
	renderer->setCameraPos(m_cameraX, m_cameraY);

	//begin drawing sprites
	renderer->begin();

	// draw textures and text
	switch (gameState)
	{
	case MissionBoard:

		char MissionText[32];
		sprintf_s(MissionText, 32, "CHOOSE A MONSTER TO FIGHT");
		renderer->drawText(m_font, MissionText, 900, 1000);
	
		break;

	case Combat:
		PlayerChar->eDraw(renderer);
		MonsterChar->eDraw(renderer);

		//show Player Name and hp
		char pName[32];
		sprintf_s(pName, 32, PlayerChar->getName());
		renderer->drawText(m_font, pName, 425, 580);
		char pHp[32];
		sprintf_s(pHp, 32, "%i", PlayerChar->getHp());
		renderer->drawText(m_font, pHp, 450, 555);

		char mName[32];
		sprintf_s(mName, 32, MonsterChar->getName());
		renderer->drawText(m_font, mName, 1400, 580);
		char mHp[32];
		sprintf_s(mHp, 32, "%i", MonsterChar->getHp());
		renderer->drawText(m_font, mHp, 1440, 555);

		if (PlayerChar->isAlive() == false)
		{
			char deadText[32];
			sprintf_s(deadText, 32, "YOU DIED");
			renderer->drawText(m_font, deadText, 600, 600);
		}

		if (gameState == Combat && combatTurn == PTurn)
		{
			char TurnText[32];
			sprintf_s(TurnText, 32, "PLAYER TURN");
			renderer->drawText(m_font, TurnText, 900, 1000);
		}

		if (gameState == Combat && combatTurn == MTurn)
		{
			char TurnText[32];
			sprintf_s(TurnText, 32, "MONSTER TURN");
			renderer->drawText(m_font, TurnText, 900, 1000);
		}

	case Shop:
		break;
	}

	//drawing buttons
	switch (gameState)
	{
	case MissionBoard:

		ImGui::BeginMenu("");
		if (ImGui::Button("Kelbi", ImVec2(100, 50)))
		{
			gameState = Combat;
			/*MonsterChar = Kelbi;*/
		}
		if (ImGui::Button("Qurupeco", ImVec2(100, 50)))
		{
			gameState = Combat;
		/*	MonsterChar = Quru;*/
		}
		if (ImGui::Button("Rathalos", ImVec2(100, 50)))
		{
			gameState = Combat;
			/*MonsterChar = Rathalos;*/
		}
	
		break;

	case Combat:
		//Menu
		ImGui::BeginMenu("Battle");
		if (ImGui::Button("Attack", ImVec2(100, 50)))
		{
			PlayerChar->eState = Entity::EntityState::Attacking;
		}
		if (ImGui::Button("Items", ImVec2(100, 50)))
		{

		}
		if (ImGui::Button("Guard", ImVec2(100, 50)))
		{

		}
		if (ImGui::Button("Flee", ImVec2(100, 50)))
		{
			gameState = Shop;
		}

		break;
	}

	renderer->end();
}










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

////draw monster
//renderer->setUVRect(0, 0, 1, 1);
//renderer->drawSprite(m_Rath, 1200, 400, 0, 0, 0, 1, 0, 0);

//renderer->drawSprite(m_CurPlayerAnimation, 400, 600, 222, 144, 0, 1, 0, 0);

////animate monster
//renderer->setUVRect(int(m_timer * 8) % 14 / 14.0f, 0, 1.f / 14, 1.f);

////846 x 546
//renderer->drawSprite(m_CurMonAnimation, 1000, 535, 846, 546, 0, 1, 0, 0);