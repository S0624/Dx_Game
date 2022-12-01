#pragma once
#include"Vec2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	virtual void init();		//�G�l�~�[�̏�����
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }		//�G�l�~�[�̉摜�ǂݍ���
	void setSpeed(float speed) { m_speed = speed; }			//�G�l�~�[�̈ړ����x�̏���
	virtual void updata();									//�G�l�~�[�̍X�V����
	virtual void draw();									//�G�l�~�[�̕`��


	bool isExsist()const { return m_isExist; }		//���݂��邩

	Vec2 getPos() const { return m_pos; }		//���̎擾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//�E����W�̎擾

private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	int m_handle;
	float m_speed;

	bool m_isExist;		//���݂��邩

	int m_waitFrame;	//�G�̐�������
};