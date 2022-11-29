#include<DxLib.h>
#include"Player.h"
#include"Pad.h"
#include"game.h"

namespace
{
	constexpr float kJumpAcc = -21.0f;			//ジャンプ力
	constexpr float kGravity = 0.6f;			//重力

	//constexpr int kWaitFrameMin = 60;		//待ち時間
	//constexpr int kWaitFrameMax = 180;		//待ち時間
}

Player::Player() :
	m_pos(),
	m_vec(),
	m_size(),
	m_isDead(),
	m_fieldY(),
	m_handle(-1)/*,
	m_waitFrame(0)*/
{

}

Player::~Player()
{

}

void Player::init()
{
	//m_waitFrame = GetRand(kWaitFrameMax) + kWaitFrameMin;
	m_pos.x = 40;
	//m_pos.y = Game::kScreenHeight - m_fieldY;
	m_pos.y = 590;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	//m_handle = LoadGraph("date/usa_Normal.png");
	//m_handle = LoadGraph("date/usa_Over.png");

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);

}

void Player::updata()
{
	/*if (m_waitFrame > 0)
	{
		m_waitFrame--;
		return;
	}*/
	if (m_isDead) return;

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
	if (m_isDead)
	{
		DrawGraph(m_pos.x, m_pos.y, m_handle, true);
		return;
	}
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}