#pragma once
#include"SceneBase.h"
//#include"Player.h"
//#include"Enemy.h"
#include<vector>

class Player;
class Enemy;

class SceneMain : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init()override;
	virtual void end()override {}

	virtual void update()override;
	virtual void draw() override;

	virtual bool isCol();

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;

	Player* m_pPlayer;
	std::vector<Enemy*> m_pEnemy;
};