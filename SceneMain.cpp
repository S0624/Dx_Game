#include"DxLib.h"
#include"SceneMain.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "���C��";
	const char* const kExplanationText = "1�{�^���������Ă�������";

	// �n�ʂ̍���
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
	//	m_isEnd = true;					//main�ɐ؂�ւ�
	//}
}

void SceneMain::draw()
{
	m_pPlayer->draw();

	// �n�ʂ̕`��
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));

	//DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	//DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
}

