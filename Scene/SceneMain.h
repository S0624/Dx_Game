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

	virtual void init()override;			//初期化
	virtual void end()override;

	virtual void update()override;			//更新処理
	virtual void draw() override;			//描画処理

	int getscore() const;					//scoreを渡す
	virtual bool isCol();					//当たり判定

	virtual bool isEnd()override { return m_isEnd; }		//シーンの切り替え
private:
	bool m_isEnd;				//シーンの終了フラグ
	int m_Playerhandle;			//プレイヤーハンドル
	int m_PlayerOverhandle;		//プレイヤーゲームオーバーハンドル
	int m_Enemyhandle;			//エネミーハンドル
	int m_backgroundcolor;		//フェード

	Player* m_pPlayer;				//プレイヤークラス
	Enemy* m_pEnemy;				//エネミークラス
};