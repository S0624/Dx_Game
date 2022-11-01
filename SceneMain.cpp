#include"DxLib.h"
#include"SceneMain.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "メイン";
	const char* const kExplanationText = "1ボタンを押してください";

	// 地面の高さ
	constexpr float kFieldY = 690.0f;
}

SceneMain::SceneMain():
	m_isEnd(-1),
	m_pPlayer(nullptr)
{
	m_pPlayer = new Player;
}

SceneMain::~SceneMain()
{
	delete(m_pPlayer);
}

void SceneMain::init()
{
	m_isEnd = false;
	m_pPlayer->init();
	m_pPlayer->setup(kFieldY);
}


void SceneMain::update()
{
	m_pPlayer->updata();
	
	//if (Pad::isTrigger(PAD_INPUT_1))
	//{
	//	m_isEnd = true;					//mainに切り替え
	//}
}

void SceneMain::draw()
{
	m_pPlayer->draw();

	// 地面の描画
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));

	//DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	//DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//タイトル画面の表示
}

