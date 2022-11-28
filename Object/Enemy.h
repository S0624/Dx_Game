#pragma once
#include"Vec2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	//virtual void start(Vec2 pos);	//�G�l�~�[�̐����J�n

	virtual void init();
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }
	void setSpeed(float speed) { m_speed = speed; }
	virtual void updata();
	virtual void draw();


	bool isExsist()const { return m_isExist; }		//���݂��邩

	Vec2 getPos() const { return m_pos; }		//���̎擾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//�E����W�̎擾

//	virtual void setup(float fieldY) { m_fieldY = fieldY; }

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	int m_handle;
	float m_speed;

	bool m_isExist;		//���݂��邩

	int m_waitFrame;

	//	float m_fieldY;
};