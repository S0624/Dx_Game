#include<DxLib.h>
#include"SceneMain.h"
#include"Player.h"
#include"Enemy.h"
#include"Pad.h"
#include"game.h"
#include"SceneResult.h"
#include<cassert>

namespace
{
	const char* const kTitleText = "メイン";
	const char* const kExplanationText = "1ボタンを押してください";

	constexpr int kEnemyMax = 3;
	int kScorecount = 0;
	// 地面の高さ
	constexpr float kFieldY = 690.0f;
	int kColorbackground = 0;
}

SceneMain::SceneMain() :
	m_isEnd(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr),
	m_Playerhandle(-1),
	m_PlayerOverhandle(-1),
	m_Enemyhandle(),
	m_backgroundcolor()
{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
	m_Playerhandle = LoadGraph("date/usa_Normal.png");			//プレイヤーの画像セット
	m_PlayerOverhandle = LoadGraph("date/usa_Over.png");		//死亡時の画像セット
	m_Enemyhandle = LoadGraph("date/Enemy_blue.png");			//エネミーの画像セット

	m_pPlayer->setGraph(m_Playerhandle);					//各クラスに画像をセットする
	m_pEnemy->setGraph(m_Enemyhandle);						//各クラスに画像をセットする

	m_backgroundcolor = 7;
}

SceneMain::~SceneMain()
{
	delete(m_pPlayer);
	delete(m_pEnemy);

	DeleteGraph(m_Playerhandle);				//画像の消去
	DeleteGraph(m_PlayerOverhandle);			//画像の消去
	DeleteGraph(m_Enemyhandle);					//画像の消去
}

void SceneMain::init()
{
	kScorecount = 0;				//scoreのカウント
	m_isEnd = false;				//シーンの切り替え
	m_pPlayer->init();				//初期化
	m_pPlayer->setup(kFieldY);		//床の線の受け渡し
	m_pPlayer->setGraph(m_Playerhandle);
	m_pPlayer->Dead(false);
	m_pEnemy->init();
}

void SceneMain::end()
{
	DeleteGraph(m_Playerhandle);
	DeleteGraph(m_PlayerOverhandle);
	DeleteGraph(m_Enemyhandle);
}

void SceneMain::update()
{
	kColorbackground += m_backgroundcolor;
	if (m_pPlayer->isDead() == false)
	{
		if (kColorbackground < 255)
		{
			return;
		}
	}
	
	if (kColorbackground > 255)
	{
		kColorbackground = 255;
	}
	m_pPlayer->updata();
	m_pEnemy->updata();
	if (m_pPlayer->isDead() == true)
	{
		DrawFormatString(400, 450, GetColor(255, 255, 255), "GameOver");
		DrawFormatString(400, 500, GetColor(255, 255, 255), "1ボタンを押してください");
		if (Pad::isTrigger(PAD_INPUT_1))		//ボタンを押されたらフェード処理の開始
		{
			m_backgroundcolor *= -1;
		}

		if (kColorbackground < 0)			//フェードしきったらシーンを変える
		{
			m_isEnd = true;					//resultに切り替え
			m_backgroundcolor = 7;
			kColorbackground = 0;
		}
	}

	if (isCol() == false)				//プレイヤーが敵に当たってなければscoreをカウントする
	{
		if (m_pPlayer->isDead() == false)
		{
			kScorecount++;
		}
		m_pEnemy->setSpeed(5.5);			//scoreによってスピードを変化
		if (kScorecount > 1000)
		{
			m_pEnemy->setSpeed(7.5);
		}
		if (kScorecount > 2500)
		{
			m_pEnemy->setSpeed(9.5);
		}
		if (kScorecount > 5000)
		{
			m_pEnemy->setSpeed(11.5);
		}
	}
	if (isCol() == true)				//プレイヤーが敵に当たったらプレイヤーを死亡させる
	{
		m_pPlayer->setGraph(m_PlayerOverhandle);
		m_pPlayer->Dead(true);
	}
}
int SceneMain::getscore()const
{
	int Scorecount = 0;
	Scorecount = kScorecount;
	return Scorecount;
}

void SceneMain::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	m_pPlayer->draw();
	m_pEnemy->draw();

	// 地面の描画
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));
	DrawFormatString(0, 150, GetColor(255, 255, 255), "score : %d", kScorecount);
	if (kScorecount <= 1000)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "SpeedLevel : 1");
	}
	if (kScorecount > 1000 && kScorecount <= 2500)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "SpeedLevel : 2");
	}
	if (kScorecount > 2500 && kScorecount <= 5000)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "SpeedLevel : 3");
	}
	if (kScorecount > 5000)
	{
		DrawFormatString(0, 100, GetColor(255, 255, 255), "SpeedLevel : 4");
	}
}

bool SceneMain::isCol()
{
	if (m_pEnemy->isExsist() == true) return false;
	if (m_pPlayer->getPos().x > m_pEnemy->getBottomRight().x ||				//プレイヤーと敵の当たり判定
		m_pPlayer->getBottomRight().x < m_pEnemy->getPos().x ||
		m_pPlayer->getPos().y > m_pEnemy->getBottomRight().y ||
		m_pPlayer->getBottomRight().y < m_pEnemy->getPos().y)
	{
		return false;							//当たっていたらtrueを返す
	}
	return true;
}