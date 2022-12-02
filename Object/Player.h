#pragma once
#include"Vec2.h"

class Player
{
public:
	Player();
	~Player();

	virtual void init();		//�v���C���[�̏�����
	virtual void end() {}
	void setGraph(int handle) { m_handle = handle; }		//�v���C���[�̉摜�Z�b�g
	virtual void updata();			//�v���C���[�̍X�V����
	virtual void draw();			//�v���C���[�̕`��

	void Dead(bool isDead) { m_isDead = isDead; }			//�v���C���[�̎��S����

	virtual void setup(float fieldY) { m_fieldY = fieldY; }	//���̔���

	Vec2 getPos() const { return m_pos; }		//���̎擾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//�E����W�̎擾

	bool isDead()const { return m_isDead; }					//�v���C���[�̎��S����

private:
	Vec2 m_pos;			//�v���C���[�|�W�V����
	Vec2 m_vec;			//�v���C���[��Jump�����Ɏg�p
	Vec2 m_size;		//�O���t�T�C�Y
	int m_handle;		//�v���C���[�n���h��

	bool m_isDead;		//�v���C���[���S�t���O

	float m_fieldY;		//���̐��̂����킽��
};