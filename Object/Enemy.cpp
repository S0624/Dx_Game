#include<DxLib.h>
#include"Enemy.h"
#include"Pad.h"
#include"game.h"

namespace
{
	//float kEnemySpeed = -0.0f;			//移動速度

	constexpr int kWaitFrameMin = 30;		//待ち時間
	constexpr int kWaitFrameMax = 180;		//待ち時間
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

void Enemy::init()						//初期化処理
{
	m_waitFrame = GetRand(kWaitFrameMax) + kWaitFrameMin;		//敵の生成時間をランダムで生成する
	m_pos.x = Game::kScreenWindth;								//初期位置は画面の右端にする
	m_pos.y = 590;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_speed;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);				//画像サイズを得る
}

void Enemy::updata()				//更新処理
{
	if (m_waitFrame > 0)			//ランダムでわたされた数値が0になるまで処理を行わない
	{
		m_waitFrame--;
		return;
	}

	m_vec.x = -m_speed;				//エネミーの移動開始
	m_pos += m_vec;

	if (m_pos.x < 0 - m_size.y)		//エネミーが画面外に行ったら存在を消す
	{
		m_pos.x = 0 - m_size.y;
		m_isExist = true;
	}

	if (m_isExist == true)			//存在が消されたら新たなエネミーを生成する
	{
		init();
		m_isExist = false;
	}
	
}

void Enemy::draw()					//エネミーの描画
{
	if (m_isExist)return;			//エネミーが存在しなかったら描画しない
	DrawGraph(m_pos.x, m_pos.y, m_handle, true);
}