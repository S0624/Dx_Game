#include<DxLib.h>
#include"SceneResult.h"
#include"game.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "リザルト";
	const char* const kExplanationText = "1ボタンを押してください";
	int kColorbackground = 0;
	int kColorletter = 255;
}
SceneResult::SceneResult() :
	m_isEnd(-1),
	m_handle(),
	m_backgroundcolor()
{
	m_handle = LoadGraph("date/frame1.png");
	m_backgroundcolor = 7;
}

void SceneResult::update()
{
	kColorbackground += m_backgroundcolor;
	if (kColorbackground > 255)
	{
		kColorbackground = 255;
	}
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_backgroundcolor *= -1;
	}

	if (kColorbackground < 0)
	{
		m_isEnd = true;					//mainに切り替え
		m_backgroundcolor = 7;
		kColorbackground = 0;
	}
}

void SceneResult::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	DrawGraph(0, 0, m_handle, true);
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 200, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//タイトル画面の表示
}
