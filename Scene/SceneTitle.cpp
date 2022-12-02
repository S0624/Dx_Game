#include<DxLib.h>
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "Jump";				//表示タイトルテキスト
	const char* const kExplanationText = "1ボタンを押してください";		//表示ガイドテキスト
	int kColorbackground = 0;				//背景カラー
	int kColorletter = 255;					//文字カラー
	constexpr int kWaitFrameMin = 120;		//待ち時間
}

SceneTitle::SceneTitle() :
	m_isEnd(-1),
	m_waitFrame(),
	m_handle(),
	m_backgroundcolor()
{
	m_waitFrame = kWaitFrameMin;		//待ち時間を代入
	m_handle = LoadGraph("date/frame1.png");		//背景のセット
	m_backgroundcolor = 7;
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_handle);				//シーンが終了したら画像の消去
}

void SceneTitle::update()
{
	kColorbackground +=  m_backgroundcolor;			//フェード処理
	if (kColorbackground > 255)						//255より大きくなったら255を入れる
	{
		kColorbackground = 255;
	}
	if (Pad::isTrigger(PAD_INPUT_1))				//ボタンが押されたらフェードを開始
	{
		m_backgroundcolor *= -1;
	}

	if (kColorbackground < 0)					//フェードして色が0になったらシーンを切り変える
	{
		m_isEnd = true;					//mainに切り替え
		m_backgroundcolor = 7;
		kColorbackground = 0;
	}

	if (m_waitFrame > 0)				//文字を点滅させる処理
	{
		m_waitFrame--;
		return;
	}
	
	if (m_waitFrame == 0)				//待ち時間が0になったら色を変えていく処理
	{
		kColorletter += -7;
	}

	if (kColorletter < 0)				//0より大きくなったら255に戻し繰り返す
	{
		kColorletter = 255;
		m_waitFrame = kWaitFrameMin;
	}
}

void SceneTitle::draw()
{
	SetDrawBright(kColorbackground, kColorbackground, kColorbackground);		//フェード処理
	DrawGraph(0, 0, m_handle, true);				//背景の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColorletter, kColorletter, kColorletter));			//ガイドの表示
}
