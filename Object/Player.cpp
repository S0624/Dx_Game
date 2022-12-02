#include<DxLib.h>
#include"Player.h"
#include"Pad.h"
#include"game.h"

namespace
{
	constexpr float kJumpAcc = -21.0f;			//�W�����v��
	constexpr float kGravity = 0.6f;			//�d��
}

Player::Player() :
	m_pos(),
	m_vec(),
	m_size(),
	m_isDead(),
	m_fieldY(),
	m_handle(-1)
{

}

Player::~Player()
{

}

void Player::init()
{
	m_pos.x = 40;			//�v���C���[�̏����ʒu
	m_pos.y = 590;			//�v���C���[�̏����ʒu
	m_vec.x = 0.0f;			//�v���C���[��Jump���x
	m_vec.y = 0.0f;			//�v���C���[��Jump���x

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);		//�v���C���[�̃O���t�T�C�Y�̎擾
}

void Player::updata()
{
	if (m_isDead) return;		//�v���C���[�����S���Ă�����ȉ��̏������s��Ȃ�

	m_pos += m_vec;				//�v���C���[��Jump���x

	//�n�ʂƂ̓�����
	bool isField = false;

	if (m_pos.y > m_fieldY - m_size.y)			//���ɓ������Ă�����Jump����
	{
		m_pos.y = m_fieldY - m_size.y;
		isField = true;							//���ł���Ԃ�true��Ԃ�
	}

	// �L�[���͏���

	if (Pad::isPress(PAD_INPUT_1))				//�{�^���������ꂽ��Jump������
	{
		if (isField)						//���ɓ������Ă����珈��������
		{
			m_vec.y = kJumpAcc;				//�W�����v�J�n
		}
	}
	m_vec.y += kGravity;					//�d�͂𑫂�
}

void Player::draw()
{
	if (m_isDead)							//����ł����珈�����s��Ȃ�
	{
		DrawGraph(m_pos.x, m_pos.y, m_handle, true);		//���S���Ă����ꍇ�̉摜�\��
		return;
	}
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);			//�摜�\��
}