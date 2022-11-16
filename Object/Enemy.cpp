#include"DxLib.h"
#include"Enemy.h"
#include"Pad.h"

namespace
{
	float kEnemySpeed = -3.5f;			//移動速度
}

Enemy::Enemy() :
	m_pos(),
	m_vec(),
	m_size(),
	m_isExist(false)
{

}

Enemy::~Enemy()
{

}

//void Enemy::start(Vec2 pos)
//{
//	m_isExist = true;
//	m_pos = pos;
//}

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
	m_vec.x = kEnemySpeed ;
	m_pos += m_vec;

	if (m_pos.x < 0 - 40)
	{
		m_isExist = true;
	}
}

void Enemy::draw()
{
	if (m_isExist)return;
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, GetColor(255, 0, 255), false);
	
	DrawBox(getPos().x - 5, getPos().y - 5, getPos().x  + m_size.x + 5, getPos().y + m_size.y + 5, GetColor(255, 255, 255), false);		//デバッグ用に当たり判定


	DrawFormatString(0, 100, GetColor(255, 255, 255), "x:%f", m_pos.x);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "y:%f", m_pos.y);
}