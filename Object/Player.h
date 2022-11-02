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
	
	virtual void setup(float fieldY) { m_fieldY = fieldY; }

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

	float m_fieldY;
};