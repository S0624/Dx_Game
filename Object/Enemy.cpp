#include"DxLib.h"
#include"Enemy.h"
#include"Pad.h"

namespace
{
	constexpr float kJumpAcc = -18.0f;			//ÉWÉÉÉìÉvóÕ
	constexpr float kGravity = 0.6f;			//èdóÕ
}

Enemy::Enemy() :
	m_pos(),
	m_vec(),
	m_size()
{

}

Enemy::~Enemy()
{

}

void Enemy::init()
{
	m_pos.x = 700;
	m_pos.y = 650;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_size.x = 40;
	m_size.y = 40;
}

void Enemy::updata()
{
	m_pos += m_vec;
}

void Enemy::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, GetColor(255, 0, 255), false);

	DrawFormatString(0, 60, GetColor(255, 0, 255), "x:%f", m_pos.x);
	DrawFormatString(0, 80, GetColor(255, 0, 255), "y:%f", m_pos.y);
}