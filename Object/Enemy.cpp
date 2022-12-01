#include<DxLib.h>
#include"Enemy.h"
#include"Pad.h"
#include"game.h"

namespace
{
	//float kEnemySpeed = -0.0f;			//�ړ����x

	constexpr int kWaitFrameMin = 30;		//�҂�����
	constexpr int kWaitFrameMax = 180;		//�҂�����
}

Enemy::Enemy() :
	m_pos(),
	m_vec(),
	m_size(),
	m_handle(-1),
	m_speed(1),
	m_isExist(false),
	m_waitFrame(0)
{

}

Enemy::~Enemy()
{

}

void Enemy::init()						//����������
{
	m_waitFrame = GetRand(kWaitFrameMax) + kWaitFrameMin;		//�G�̐������Ԃ������_���Ő�������
	m_pos.x = Game::kScreenWindth;								//�����ʒu�͉�ʂ̉E�[�ɂ���
	m_pos.y = 590;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_speed;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);				//�摜�T�C�Y�𓾂�
}

void Enemy::updata()				//�X�V����
{
	if (m_waitFrame > 0)			//�����_���ł킽���ꂽ���l��0�ɂȂ�܂ŏ������s��Ȃ�
	{
		m_waitFrame--;
		return;
	}

	m_vec.x = -m_speed;				//�G�l�~�[�̈ړ��J�n
	m_pos += m_vec;

	if (m_pos.x < 0 - m_size.y)		//�G�l�~�[����ʊO�ɍs�����瑶�݂�����
	{
		m_pos.x = 0 - m_size.y;
		m_isExist = true;
	}

	if (m_isExist == true)			//���݂������ꂽ��V���ȃG�l�~�[�𐶐�����
	{
		init();
		m_isExist = false;
	}
	
}

void Enemy::draw()					//�G�l�~�[�̕`��
{
	if (m_isExist)return;			//�G�l�~�[�����݂��Ȃ�������`�悵�Ȃ�
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}