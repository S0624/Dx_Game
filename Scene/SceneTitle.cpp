#include<DxLib.h>
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "Jump";				//�\���^�C�g���e�L�X�g
	const char* const kExplanationText = "1�{�^���������Ă�������";		//�\���K�C�h�e�L�X�g
	int kColorbackground = 0;				//�w�i�J���[
	int kColorletter = 255;					//�����J���[
	constexpr int kWaitFrameMin = 120;		//�҂�����
}

SceneTitle::SceneTitle() :
	m_isEnd(-1),
	m_waitFrame(),
	m_handle(),
	m_backgroundcolor()
{
	m_waitFrame = kWaitFrameMin;		//�҂����Ԃ���
	m_handle = LoadGraph("date/frame1.png");		//�w�i�̃Z�b�g
	m_backgroundcolor = 7;
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_handle);				//�V�[�����I��������摜�̏���
}

void SceneTitle::update()
{
	kColorbackground +=  m_backgroundcolor;			//�t�F�[�h����
	if (kColorbackground > 255)						//255���傫���Ȃ�����255������
	{
		kColorbackground = 255;
	}
	if (Pad::isTrigger(PAD_INPUT_1))				//�{�^���������ꂽ��t�F�[�h���J�n
	{
		m_backgroundcolor *= -1;
	}

	if (kColorbackground < 0)					//�t�F�[�h���ĐF��0�ɂȂ�����V�[����؂�ς���
	{
		m_isEnd = true;					//main�ɐ؂�ւ�
		m_backgroundcolor = 7;
		kColorbackground = 0;
	}

	if (m_waitFrame > 0)				//������_�ł����鏈��
	{
		m_waitFrame--;
		return;
	}
	
	if (m_waitFrame == 0)				//�҂����Ԃ�0�ɂȂ�����F��ς��Ă�������
	{
		kColorletter += -7;
	}

	if (kColorletter < 0)				//0���傫���Ȃ�����255�ɖ߂��J��Ԃ�
	{
		kColorletter = 255;
		m_waitFrame = kWaitFrameMin;
	}
}

void SceneTitle::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);		//�t�F�[�h����
	DrawGraph(0, 0, m_handle, true);				//�w�i�̕\��
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//�K�C�h�̕\��
}
