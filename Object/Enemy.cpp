#include<DxLib.h>
#include"Enemy.h"
#include"Pad.h"
#include"game.h"

namespace
{
	float kEnemySpeed = -5.5f;			//移動速度

	constexpr int kWaitFrameMin = 60;		//待ち時間
	constexpr int kWaitFrameMax = 180;		//待ち時間
}

Enemy::Enemy() :
	m_pos(),
	m_vec(),
	m_size(),
	m_handle(-1),
	m_isExist(false),
	m_waitFrame(0)
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
	m_waitFrame = GetRand(kWaitFrameMax) + kWaitFrameMin;
	m_pos.x = Game::kScreenWindth;
	m_pos.y = 590;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	//m_handle = LoadGraph("date/Enemy_blue.png");

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

void Enemy::updata()
{
	if (m_waitFrame > 0)
	{
		m_waitFrame--;
		return;
	}

	m_vec.x = kEnemySpeed ;
	m_pos += m_vec;

	if (m_pos.x < 0 - m_size.y)
	{
		m_pos.x = 0 - m_size.y;
		m_isExist = true;
	}
}

void Enemy::draw()
{
	DrawFormatString(0, 200, GetColor(255, 0, 0), "w:%f", m_waitFrame);
	if (m_isExist)return;
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
	
	DrawBox(getPos().x - 5, getPos().y - 5, getPos().x  + m_size.x + 5, getPos().y + m_size.y + 5, GetColor(255, 255, 255), false);		//デバッグ用に当たり判定


	DrawFormatString(0, 100, GetColor(255, 255, 255), "x:%f", m_pos.x);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "y:%f", m_pos.y);
}