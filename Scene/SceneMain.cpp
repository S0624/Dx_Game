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
}

SceneMain::SceneMain():
	m_isEnd(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr),
	m_Plauerhandle(-1),
	m_Enemyhandle()
{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
	
	m_pPlayer->setGraph( LoadGraph("date/usa_Normal.png"));
	m_pEnemy->setGraph( LoadGraph("date/Enemy_blue.png"));
}

SceneMain::~SceneMain()
{
	delete(m_pPlayer);
	delete(m_pEnemy);

}

void SceneMain::init()
{
	m_isEnd = false;
	m_pPlayer->init();
	m_pPlayer->setup(kFieldY);	
	m_pEnemy->init();
}

void SceneMain::end()
{

	//DeleteGraph(handle);
}

void SceneMain::update()
{
	m_pPlayer->updata();
	m_pEnemy->updata();

	//if (Pad::isTrigger(PAD_INPUT_1))
	//{
	//	m_isEnd = true;					//mainに切り替え
	//}
	//std::vector<Enemy*>::iterator it = m_pEnemy.begin();
	////while (it != m_pEnemy.end())
	//{
	//	auto& pEnemy = (*it);

	//	assert(pEnemy);				//バグがあったらわざと止める処理
	//	pEnemy->updata();

	//for (auto& pEnemy : m_pEnemy)
	//{
	//	//pEnemy->updata();
	//
	//	if (m_pPlayer->getPos().x > pEnemy->getBottomRight().x ||				//shotと敵の当たり判定
	//		m_pPlayer->getBottomRight().x < pEnemy->getPos().x ||
	//		m_pPlayer->getPos().y > pEnemy->getBottomRight().y ||
	//		m_pPlayer->getBottomRight().y < pEnemy->getPos().y)
	//	{
	//		DrawString(0, 250, "当たってない", GetColor(255, 255, 255));								//当たっていたらtrueを返す
	//	}
	//	else
	//	{
	//		DrawString(0, 250, "当たった", GetColor(255, 255, 255));												//当たっていなかったらfalseを返す
	//	}
	//}

	if (isCol() == false)
	{
		DrawString(0, 600, "当たってない", GetColor(255, 255, 255));
	}
	if (isCol() == true)
	{
		m_pPlayer->setGraph(LoadGraph("date/usa_Over.png"));
		m_pPlayer->Dead();
		DrawString(0, 500, "当たった", GetColor(255, 255, 255));
	}
}
void SceneMain::draw()
{
	m_pPlayer->draw();
	m_pEnemy->draw();

	// 地面の描画
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));

	DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f", m_pEnemy->getPos().x);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "y:%f", m_pEnemy->getBottomRight().y);

	//DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	//DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//タイトル画面の表示
}

bool SceneMain::isCol()
{
	//if (pEnemy->isExsist() == false)
	if (m_pPlayer->getPos().x > m_pEnemy->getBottomRight().x ||				//shotと敵の当たり判定
		m_pPlayer->getBottomRight().x < m_pEnemy->getPos().x ||
		m_pPlayer->getPos().y > m_pEnemy->getBottomRight().y ||
		m_pPlayer->getBottomRight().y < m_pEnemy->getPos().y)
	{
		return false;							//当たっていたらtrueを返す
	}
	return true;
}