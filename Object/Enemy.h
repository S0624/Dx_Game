#pragma once
#include"Vec2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	virtual void init();		//エネミーの初期化
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }		//エネミーの画像読み込み
	void setSpeed(float speed) { m_speed = speed; }			//エネミーの移動速度の処理
	virtual void updata();									//エネミーの更新処理
	virtual void draw();									//エネミーの描画


	bool isExsist()const { return m_isExist; }		//存在するか

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	int m_handle;
	float m_speed;

	bool m_isExist;		//存在するか

	int m_waitFrame;	//敵の生成時間
};