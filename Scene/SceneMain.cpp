#include<DxLib.h>
#include"SceneMain.h"
#include"Player.h"
#include"Enemy.h"
#include"Pad.h"
#include"game.h"
#include<cassert>

namespace
{
	const char* const kTitleText = "���C��";
	const char* const kExplanationText = "1�{�^���������Ă�������";

	constexpr int kEnemyMax = 3;
	// �n�ʂ̍���
	constexpr float kFieldY = 690.0f;
}

SceneMain::SceneMain():
	m_isEnd(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr),
	m_Plauerhandle(-1),
	m_Enemyhandle()
{
	m_pPlayer = new Player;
	m_pEnemy = new Enemy;
	
	m_pPlayer->setGraph( LoadGraph("date/usa_Normal.png"));
	m_pEnemy->setGraph( LoadGraph("date/Enemy_blue.png"));
}

SceneMain::~SceneMain()
{
	delete(m_pPlayer);
	delete(m_pEnemy);

}

void SceneMain::init()
{
	m_isEnd = false;
	m_pPlayer->init();
	m_pPlayer->setup(kFieldY);	
	m_pEnemy->init();
}

void SceneMain::end()
{

	//DeleteGraph(handle);
}

void SceneMain::update()
{
	m_pPlayer->updata();
	m_pEnemy->updata();

	//if (Pad::isTrigger(PAD_INPUT_1))
	//{
	//	m_isEnd = true;					//main�ɐ؂�ւ�
	//}
	//std::vector<Enemy*>::iterator it = m_pEnemy.begin();
	////while (it != m_pEnemy.end())
	//{
	//	auto& pEnemy = (*it);

	//	assert(pEnemy);				//�o�O����������킴�Ǝ~�߂鏈��
	//	pEnemy->updata();

	//for (auto& pEnemy : m_pEnemy)
	//{
	//	//pEnemy->updata();
	//
	//	if (m_pPlayer->getPos().x > pEnemy->getBottomRight().x ||				//shot�ƓG�̓����蔻��
	//		m_pPlayer->getBottomRight().x < pEnemy->getPos().x ||
	//		m_pPlayer->getPos().y > pEnemy->getBottomRight().y ||
	//		m_pPlayer->getBottomRight().y < pEnemy->getPos().y)
	//	{
	//		DrawString(0, 250, "�������ĂȂ�", GetColor(255, 255, 255));								//�������Ă�����true��Ԃ�
	//	}
	//	else
	//	{
	//		DrawString(0, 250, "��������", GetColor(255, 255, 255));												//�������Ă��Ȃ�������false��Ԃ�
	//	}
	//}

	if (isCol() == false)
	{
		DrawString(0, 600, "�������ĂȂ�", GetColor(255, 255, 255));
	}
	if (isCol() == true)
	{
		m_pPlayer->setGraph(LoadGraph("date/usa_Over.png"));
		m_pPlayer->Dead();
		DrawString(0, 500, "��������", GetColor(255, 255, 255));
	}
}
void SceneMain::draw()
{
	m_pPlayer->draw();
	m_pEnemy->draw();

	// �n�ʂ̕`��
	DrawLine(0, kFieldY, Game::kScreenWindth, kFieldY, GetColor(255, 255, 255));

	DrawFormatString(0, 60, GetColor(255, 255, 255), "x:%f", m_pEnemy->getPos().x);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "y:%f", m_pEnemy->getBottomRight().y);

	//DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	//DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
}

bool SceneMain::isCol()
{
	//if (pEnemy->isExsist() == false)
	if (m_pPlayer->getPos().x > m_pEnemy->getBottomRight().x ||				//shot�ƓG�̓����蔻��
		m_pPlayer->getBottomRight().x < m_pEnemy->getPos().x ||
		m_pPlayer->getPos().y > m_pEnemy->getBottomRight().y ||
		m_pPlayer->getBottomRight().y < m_pEnemy->getPos().y)
	{
		return false;							//�������Ă�����true��Ԃ�
	}
	return true;
}