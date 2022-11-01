#include"DxLib.h"
#include"Player.h"
#include"Pad.h"

namespace
{
	constexpr float kJumpAcc = -16.0f;			//�W�����v��
	constexpr float kGravity = 0.6f;			//�d��
}

Player::Player() :
	m_pos(),
	m_vec(),
	m_size(),
	m_isField(false),
	m_fieldY()
{

}

Player::~Player()
{

}

void Player::init()
{
	m_pos.x = 10;
	m_pos.y = m_fieldY - 40;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_size.x = 40;
	m_size.y = 40;
}

void Player::updata()
{
	m_pos += m_vec;

	////�n�ʂƂ̓�����
	//bool isField = false;
	if (m_pos.y > m_fieldY)
	//if (m_pos.y > m_fieldY - m_pos.y)
	{
		m_pos.y = m_fieldY;
		//m_pos.y = m_fieldY - m_pos.y;
		m_isField = true;
	}

	// �L�[���͏���
	if (Pad::isPress(PAD_INPUT_1))
	{
		if (m_isField)
		{
			m_vec.y = kJumpAcc;				//�W�����v�J�n
		}
	}
	m_vec.y += kGravity;
}

void Player::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, GetColor(0, 255, 255), false);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", m_fieldY);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "x:%f", m_pos.x);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "y:%f", m_pos.y);
}