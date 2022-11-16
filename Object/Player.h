#pragma once
#include"Vec2.h"

class Player
{
public:
	Player();
	~Player();

	virtual void init();
	virtual void updata();
	virtual void draw();
	
	void Dead() { m_isDead = true; }

	virtual void setup(float fieldY) { m_fieldY = fieldY; }

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得
	
	bool isDead()const { return m_isDead; }

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

	bool m_isDead;

	float m_fieldY;
};