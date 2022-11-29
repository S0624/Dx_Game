#include<DxLib.h>
#include"SceneMain.h"
#include"Player.h"
#include"Enemy.h"
#include"Pad.h"
#include"game.h"
#include<cassert>

namespace
{
	const char* const kTitleText = "メイン";
	const char* const kExplanationText = "1ボタンを押してください";

	constexpr int kEnemyMax = 3;
	// 地面の高さ
	constexpr float kFieldY = 690.0f;
	int kColorbackground = 255;
}

SceneMain::SceneMain() :
	m_isEnd(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr),
	m_Playerhandle(-1),
	m_PlayerOverhandle(-1),
	m_Enemyhandle(),
	m_Scorecount()
{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
	m_Playerhandle = LoadGraph("date/usa_Normal.png");
	m_PlayerOverhandle = LoadGraph("date/usa_Over.png");
	m_Enemyhandle = LoadGraph("date/Enemy_blue.png");

	m_pPlayer->setGraph(m_Playerhandle);

	m_pEnemy->setGraph(m_Enemyhandle);
}

SceneMain::~SceneMain()
{
	delete(m_pPlayer);
	delete(m_pEnemy);
}

void SceneMain::init()
{
	m_Scorecount = 0;
	m_isEnd = false;
	m_pPlayer->init();
	m_pPlayer->setup(kFieldY);
	m_pPlayer->setGraph(m_Playerhandle);
	m_pPlayer->Dead(false);
	m_pEnemy->init();
}

void SceneMain::end()
{
	//DeleteGraph(m_Playerhandle);
	//DeleteGraph(m_PlayerOverhandle);
	//DeleteGraph(m_Enemyhandle);
}

void SceneMain::update()
{
	m_pPlayer->updata();
	m_pEnemy->updata();
	if (m_pPlayer->isDead() == true)
	{
		DrawFormatString(400, 450, GetColor(255, 255, 255), "GameOver");
		DrawFormatString(400, 500, GetColor(255, 255, 255), "1ボタンを押してください");
		if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_isEnd = true;					//mainに切り替え
		}
	}

	if (isCol() == false) 
	{
		if (m_pPlayer->isDead() == false)
		{
			m_Scorecount++;
		}
		m_pEnemy->setSpeed(5.5);
		if (m_Scorecount > 1000)
		{
			m_pEnemy->setSpeed(7.5);
		}
		if (m_Scorecount > 2500)
		{
			m_pEnemy->setSpeed(9.5);
		}
		if (m_Scorecount > 5000)
		{
			m_pEnemy->setSpeed(10.5);
		}
	}
	if (isCol() == true)
	{
		m_pPlayer->setGraph(m_PlayerOverhandle);
		m_pPlayer->Dead(true);
	}
}
void SceneMain::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	m_pPlayer->draw();
	m_pEnemy->draw();

	// 地面の描画
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));

	DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f", m_pEnemy->getPos().x);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "y:%f", m_pEnemy->getBottomRight().y);

	DrawFormatString(0, 150, GetColor(255, 255, 255), "%d", m_Scorecount);
	//if (m_Scorecount > 1000)
	/*{
		DrawFormatString(0, 400, GetColor(255, 255, 255), "SPEED UP");
	}*/
}

bool SceneMain::isCol()
{
	if (m_pEnemy->isExsist() == true) return false;
	if (m_pPlayer->getPos().x > m_pEnemy->getBottomRight().x ||				//shotと敵の当たり判定
		m_pPlayer->getBottomRight().x < m_pEnemy->getPos().x ||
		m_pPlayer->getPos().y > m_pEnemy->getBottomRight().y ||
		m_pPlayer->getBottomRight().y < m_pEnemy->getPos().y)
	{
		return false;							//当たっていたらtrueを返す
	}
	return true;
}