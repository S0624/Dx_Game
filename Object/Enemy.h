#pragma once
#include"Vec2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	//virtual void start(Vec2 pos);	//エネミーの生成開始

	virtual void init();
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }
	void setSpeed(float speed) { m_speed = speed; }
	virtual void updata();
	virtual void draw();


	bool isExsist()const { return m_isExist; }		//存在するか

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得

//	virtual void setup(float fieldY) { m_fieldY = fieldY; }

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	int m_handle;
	float m_speed;

	bool m_isExist;		//存在するか

	int m_waitFrame;

	//	float m_fieldY;
};