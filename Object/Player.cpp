#include<DxLib.h>
#include"Player.h"
#include"Pad.h"
#include"game.h"

namespace
{
	constexpr float kJumpAcc = -21.0f;			//ジャンプ力
	constexpr float kGravity = 0.6f;			//重力
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
	m_pos.x = 40;			//プレイヤーの初期位置
	m_pos.y = 590;			//プレイヤーの初期位置
	m_vec.x = 0.0f;			//プレイヤーのJump速度
	m_vec.y = 0.0f;			//プレイヤーのJump速度

	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);		//プレイヤーのグラフサイズの取得
}

void Player::updata()
{
	if (m_isDead) return;		//プレイヤーが死亡していたら以下の処理を行わない

	m_pos += m_vec;				//プレイヤーのJump速度

	//地面との当たり
	bool isField = false;

	if (m_pos.y > m_fieldY - m_size.y)			//床に当たっていたらJumpする
	{
		m_pos.y = m_fieldY - m_size.y;
		isField = true;							//飛んでいる間はtrueを返す
	}

	// キー入力処理

	if (Pad::isPress(PAD_INPUT_1))				//ボタンを押されたらJumpをする
	{
		if (isField)						//床に当たっていたら処理をする
		{
			m_vec.y = kJumpAcc;				//ジャンプ開始
		}
	}
	m_vec.y += kGravity;					//重力を足す
}

void Player::draw()
{
	if (m_isDead)							//死んでいたら処理を行わない
	{
		DrawGraph(m_pos.x, m_pos.y, m_handle, true);		//死亡していた場合の画像表示
		return;
	}
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);			//画像表示
}