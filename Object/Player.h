#pragma once
#include"Vec2.h"

class Player
{
public:
	Player();
	~Player();

	virtual void init();
	void setGraph(int handle) { m_handle = handle; }
	virtual void updata();
	virtual void draw();
	
	void Dead() { m_isDead = true; }

	virtual void setup(float fieldY) { m_fieldY = fieldY; }

	Vec2 getPos() const { return m_pos; }		//î•ñ‚Ìæ“¾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//‰EãÀ•W‚Ìæ“¾
	
	bool isDead()const { return m_isDead; }

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	int m_handle;

	bool m_isDead;

	float m_fieldY;
};