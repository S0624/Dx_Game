#include"DxLib.h"
#include"Player.h"
#include"Pad.h"

namespace
{
	constexpr float kJumpAcc = -18.0f;			//ジャンプ力
	constexpr float kGravity = 0.6f;			//重力
}

Player::Player() :
	m_pos(),
	m_vec(),
	m_size(),
	m_isDead(),
	m_fieldY()
{

}

Player::~Player()
{

}

void Player::init()
{
	m_pos.x = 40;
	m_pos.y = 650;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_size.x = 40;
	m_size.y = 40;
}

void Player::updata()
{
	m_pos += m_vec;
	//地面との当たり
	bool isField = false;
	if (m_pos.y > m_fieldY - m_size.y)
	{
		m_pos.y = m_fieldY - m_size.y;
		isField = true;
	}

	// キー入力処理

	if (Pad::isPress(PAD_INPUT_1))
	//if (Pad::isTrigger(PAD_INPUT_1))
	{
		if (isField)
		{
			m_vec.y = kJumpAcc;				//ジャンプ開始
		}
	}
	m_vec.y += kGravity;
}

void Player::draw()
{
	if (m_isDead) return;
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, GetColor(0, 255, 255), false);

	DrawBox(getPos().x - 5, getPos().y - 5, getPos().x + m_size.x + 5, getPos().y + m_size.y + 5, GetColor(255, 255, 255), false);		//デバッグ用に当たり判定

	DrawFormatString(0, 20, GetColor(255, 255, 255), "x:%f", m_pos.x);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "y:%f", m_pos.y);
}