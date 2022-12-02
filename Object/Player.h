#pragma once
#include"Vec2.h"

class Player
{
public:
	Player();
	~Player();

	virtual void init();		//プレイヤーの初期化
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }		//プレイヤーの画像セット
	virtual void updata();			//プレイヤーの更新処理
	virtual void draw();			//プレイヤーの描画

	void Dead(bool isDead) { m_isDead = isDead; }			//プレイヤーの死亡判定

	virtual void setup(float fieldY) { m_fieldY = fieldY; }	//床の判定

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得

	bool isDead()const { return m_isDead; }					//プレイヤーの死亡判定

private:
	Vec2 m_pos;			//プレイヤーポジション
	Vec2 m_vec;			//プレイヤーのJump処理に使用
	Vec2 m_size;		//グラフサイズ
	int m_handle;		//プレイヤーハンドル

	bool m_isDead;		//プレイヤー死亡フラグ

	float m_fieldY;		//床の線のうけわたし
};