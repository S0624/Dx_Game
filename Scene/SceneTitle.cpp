#include"DxLib.h"
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "�^�C�g��";
	const char* const kExplanationText = "1�{�^���������Ă�������";
	int kColor = 255;
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

	if (kColor < 254)
	{
		kColor =- 1;
	}
}

void SceneTitle::draw()
{
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//�^�C�g����ʂ̕\��
	//DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//�^�C�g����ʂ̕\��
}
