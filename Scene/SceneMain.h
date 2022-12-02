#pragma once
#include"SceneBase.h"
//#include"Player.h"
//#include"Enemy.h"
//#include<vector>

class Player;
class Enemy;

class SceneMain : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init()override;			//������
	virtual void end()override;

	virtual void update()override;			//�X�V����
	virtual void draw() override;			//�`�揈��

	int getscore() const;					//score��n��
	virtual bool isCol();					//�����蔻��

	virtual bool isEnd()override { return m_isEnd; }		//�V�[���̐؂�ւ�
private:
	bool m_isEnd;				//�V�[���̏I���t���O
	int m_Playerhandle;			//�v���C���[�n���h��
	int m_PlayerOverhandle;		//�v���C���[�Q�[���I�[�o�[�n���h��
	int m_Enemyhandle;			//�G�l�~�[�n���h��
	int m_backgroundcolor;		//�t�F�[�h

	Player* m_pPlayer;				//�v���C���[�N���X
	Enemy* m_pEnemy;				//�G�l�~�[�N���X
};