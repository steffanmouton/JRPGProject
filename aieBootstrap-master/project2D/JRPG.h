#pragma once
#include "Application.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"
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

	float m_timer;

protected:

	aie::Renderer2D*	renderer;

	

	//Each frame 153 x 150
	// TODO:: Rename Variables
	Vector2				m_PlayerPos;
	
	aie::Texture*		m_PlayerIdle;
	Rect*				m_PlayerIdleUV;
	aie::Texture*		m_PlayerAttack; 
	Rect*				m_PlayerAttackUV;
	aie::Texture*		m_PlayerDying;
	Rect*				m_PlayerDyingUV;
	aie::Texture*		m_PlayerDead;
	Rect*				m_PlayerDeadUV;



	Vector2				m_MonsterPos;
	aie::Texture*		m_MonsterIdle;
	Rect*				m_MonsterIdleUV;

	aie::Font*			m_font;

	Entity* PlayerChar;
	Entity* MonsterChar;

	Monster* Rathalos;
	Monster* Quru;
	Monster* Kelbi;

	enum GameState { MissionBoard, Combat, Shop };
	GameState gameState = MissionBoard;

	enum CombatTurn {PTurn, MTurn};
	CombatTurn combatTurn = PTurn;

	float m_cameraX, m_cameraY;
	
};

