#include"DxLib.h"
#include"SceneResult.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "���U���g";
	const char* const kExplanationText = "1�{�^���������Ă�������";
}
SceneResult::SceneResult() :
	m_isEnd(-1)
{

}

void SceneResult::update()
{
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;					//main�ɐ؂�ւ�
	}
}

void SceneResult::draw()
{
	DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
}
