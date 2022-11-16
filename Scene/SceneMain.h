#pragma once
#include"SceneBase.h"
#include"Player.h"
#include"Enemy.h"
#include<vector>

class SceneMain : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init()override;
	virtual void end()override {}

	virtual void update()override;
	virtual void draw() override;

	virtual void isCol();

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;

	Player* m_pPlayer;
	std::vector<Enemy*> m_pEnemy;
};