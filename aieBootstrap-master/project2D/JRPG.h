#pragma once
#include "Application.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
#include "Shop.h"
#include <UnorderedLinkedList.h>
#include <imgui.h>
#include <iostream>
#include <Renderer2D.h>
#include "HealingPotion.h"


class JRPG : public aie::Application
{
public:
	JRPG();
	virtual ~JRPG();

	bool startup() override;
	void shutdown() override;

	void update(float dt) override;
	void draw() override;

	void turnSwitch();

	float m_timer;

protected:

	aie::Renderer2D*	renderer;

	

	//Each frame 153 x 150
	vector2				m_PlayerPos;
	
	aie::Texture*		m_PlayerIdle;
	Rect*				m_PlayerIdleUV;
	aie::Texture*		m_PlayerAttack; 
	Rect*				m_PlayerAttackUV;
	aie::Texture*		m_PlayerDying;
	Rect*				m_PlayerDyingUV;
	aie::Texture*		m_PlayerDead;
	Rect*				m_PlayerDeadUV;


	vector2				m_MonsterPos;

	aie::Texture*		m_MonsterIdle;
	Rect*				m_MonsterIdleUV;
	aie::Texture*		m_MonsterAttack;
	Rect*				m_MonsterAttackUV;

	aie::Font*			m_font;
	 
	Player* PlayerChar;
	Monster* MonsterChar;

	Monster* Rathalos;
	Monster* Quru;
	Monster* Kelbi;

	vector2				m_ShopPos;
	aie::Texture*		m_ShopIdle;
	Rect*				m_ShopUV;




	enum GameState { MissionBoard, Combat, Items, Shop, Rewards };
	GameState FSM_gameState = MissionBoard;

	enum CombatTurn {PTurn, MTurn};
	CombatTurn FSM_combatTurn = PTurn;

	float m_cameraX, m_cameraY;
	
};

