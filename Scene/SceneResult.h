#pragma once
#include"SceneBase.h"

class SceneResult : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneResult();
	virtual ~SceneResult() {}

	virtual void init()override { m_isEnd = false; }			//初期化処理
	virtual void end()override {}

	virtual void update()override;					//更新処理
	virtual void draw() override;					//描画処理

	virtual bool isEnd()override { return m_isEnd; }		//シーンの移動処理に使用
private:
	bool m_isEnd;				//シーン終了フラグ
	int m_handle;;			//背景画像
	int m_backgroundcolor;				//背景色
};