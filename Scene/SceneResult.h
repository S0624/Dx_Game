#pragma once
#include"SceneBase.h"

class SceneResult : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
{
public:
	SceneResult();
	virtual ~SceneResult() {}

	virtual void init()override { m_isEnd = false; }			//����������
	virtual void end()override {}

	virtual void update()override;					//�X�V����
	virtual void draw() override;					//�`�揈��

	virtual bool isEnd()override { return m_isEnd; }		//�V�[���̈ړ������Ɏg�p
private:
	bool m_isEnd;				//�V�[���I���t���O
	int m_handle;;			//�w�i�摜
	int m_backgroundcolor;				//�w�i�F
};