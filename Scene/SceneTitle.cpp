#include<DxLib.h>
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "�^�C�g��";
	const char* const kExplanationText = "1�{�^���������Ă�������";
	int kColorletter = 255;
	int kColorbackground = 255;
	constexpr int kWaitFrameMin = 120;		//�҂�����
	//constexpr int kWaitFrameMax = 180;		//�҂�����
}

SceneTitle::SceneTitle() :
	m_isEnd(-1),
	m_waitFrame()
{
	m_waitFrame = kWaitFrameMin;
}

void SceneTitle::update()
{
	//int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (padState & PAD_INPUT_1)
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		//kColorbackground += -15;
		//if (kColorbackground == 0)
		{
			m_isEnd = true;					//main�ɐ؂�ւ�
		}
		//return;
	}


	if (m_waitFrame > 0)
	{
		m_waitFrame--;
		return;
	}
	
	if (m_waitFrame == 0)
	{
		kColorletter += -15;
	}
	if (kColorletter < 0)
	{
		kColorletter = 255;
		m_waitFrame = kWaitFrameMin;
	}

	//DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//�^�C�g����ʂ̕\��

}

void SceneTitle::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	DrawFormatString(0, 200, GetColor(255, 0, 0), "w:%d", m_waitFrame);
	DrawFormatString(0, 255, GetColor(255, 0, 0), "%d", kColorletter);
	DrawFormatString(0, 300, GetColor(255, 0, 0), "w:%d", kColorbackground);
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//�^�C�g����ʂ̕\��
	//DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//�^�C�g����ʂ̕\��
}
