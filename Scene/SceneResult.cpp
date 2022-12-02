#include<DxLib.h>
#include"SceneResult.h"
#include"SceneMain.h"
#include"game.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "リザルト";
	const char* const kExplanationText = "1ボタンを押してください";
	int kColorbackground = 0;
	int kColorletter = 255;
	SceneMain main;
}
SceneResult::SceneResult() :
	m_isEnd(-1),
	m_handle(),
	m_backgroundcolor()
{
	m_handle = LoadGraph("date/frame1.png");			//画像のセット
	m_backgroundcolor = 7;								//フェード処理
}

void SceneResult::update()
{
	kColorbackground += m_backgroundcolor;			//フェード処理
	if (kColorbackground > 255)						//255より大きくなったら255にする
	{
		kColorbackground = 255;
	}
	if (Pad::isTrigger(PAD_INPUT_1))				//ボタンを押したらフェードインの開始
	{
		m_backgroundcolor *= -1;
	}

	if (kColorbackground < 0)						//フェードしきったらシーンを切り返える
	{
		m_isEnd = true;					//タイトルに切り替え
		m_backgroundcolor = 7;
		kColorbackground = 0;
	}
}

void SceneResult::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	DrawGraph(0, 0, m_handle, true);
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 200, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawFormatString(590 , 350,  GetColor(255, 255, 255),"獲得score : %d",main.getscore());			//タイトル画面の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//タイトル画面の表示
}
