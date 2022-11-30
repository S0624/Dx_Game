#include<DxLib.h>
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "Jump";
	const char* const kExplanationText = "1ボタンを押してください";
	int kColorbackground = 0;
	int kColorletter = 255;
	constexpr int kWaitFrameMin = 120;		//待ち時間
}

SceneTitle::SceneTitle() :
	m_isEnd(-1),
	m_waitFrame(),
	m_handle(),
	m_backgroundcolor()
{
	m_waitFrame = kWaitFrameMin;
	m_handle = LoadGraph("date/frame1.png");
	m_backgroundcolor = 7;
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_handle);
}

void SceneTitle::update()
{
	kColorbackground +=  m_backgroundcolor;
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

	if (m_waitFrame > 0)
	{
		m_waitFrame--;
		return;
	}
	
	if (m_waitFrame == 0)
	{
		kColorletter += -7;
	}

	if (kColorletter < 0)
	{
		kColorletter = 255;
		m_waitFrame = kWaitFrameMin;
	}
}

void SceneTitle::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	DrawGraph(0, 0, m_handle, true);
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//タイトル画面の表示
}
