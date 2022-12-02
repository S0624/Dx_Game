#include<DxLib.h>
#include"SceneResult.h"
#include"SceneMain.h"
#include"game.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "���U���g";
	const char* const kExplanationText = "1�{�^���������Ă�������";
	int kColorbackground = 0;
	int kColorletter = 255;
	SceneMain main;
}
SceneResult::SceneResult() :
	m_isEnd(-1),
	m_handle(),
	m_backgroundcolor()
{
	m_handle = LoadGraph("date/frame1.png");			//�摜�̃Z�b�g
	m_backgroundcolor = 7;								//�t�F�[�h����
}

void SceneResult::update()
{
	kColorbackground += m_backgroundcolor;			//�t�F�[�h����
	if (kColorbackground > 255)						//255���傫���Ȃ�����255�ɂ���
	{
		kColorbackground = 255;
	}
	if (Pad::isTrigger(PAD_INPUT_1))				//�{�^������������t�F�[�h�C���̊J�n
	{
		m_backgroundcolor *= -1;
	}

	if (kColorbackground < 0)						//�t�F�[�h����������V�[����؂�Ԃ���
	{
		m_isEnd = true;					//�^�C�g���ɐ؂�ւ�
		m_backgroundcolor = 7;
		kColorbackground = 0;
	}
}

void SceneResult::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);
	DrawGraph(0, 0, m_handle, true);
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 200, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawFormatString(590 , 350,  GetColor(255, 255, 255),"�l��score : %d",main.getscore());			//�^�C�g����ʂ̕\��
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//�^�C�g����ʂ̕\��
}
