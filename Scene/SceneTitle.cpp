#include"DxLib.h"
#include"SceneTitle.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "�^�C�g��";
	const char* const kExplanationText = "1�{�^���������Ă�������";
}

SceneTitle::SceneTitle() :
	m_isEnd(-1)
{

}

void SceneTitle::update()
{
	//int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (padState & PAD_INPUT_1)
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;					//main�ɐ؂�ւ�
	}
}

void SceneTitle::draw()
{
	DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
}
