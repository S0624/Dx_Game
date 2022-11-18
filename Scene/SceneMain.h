#pragma once
#include"SceneBase.h"
//#include"Player.h"
//#include"Enemy.h"
//#include<vector>

class Player;
class Enemy;

class SceneMain : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init()override;
	virtual void end()override;

	virtual void update()override;
	virtual void draw() override;

	virtual bool isCol();

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;
	int m_Plauerhandle;
	int m_Enemyhandle;

	Player* m_pPlayer;
	Enemy* m_pEnemy;
};