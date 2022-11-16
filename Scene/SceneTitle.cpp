#include"DxLib.h"
#include"SceneTitle.h"
#include"Pad.h"
#include"game.h"

namespace
{
	const char* const kTitleText = "タイトル";
	const char* const kExplanationText = "1ボタンを押してください";
	int kColor = 255;
}

SceneTitle::SceneTitle() :
	m_isEnd(-1)
{

}

void SceneTitle::update()
{
	//int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//if (padState & PAD_INPUT_1)
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;					//mainに切り替え
	}

	if (kColor < 254)
	{
		kColor =- 1;
	}
}

void SceneTitle::draw()
{
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kTitleText, -1)) / 2, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//タイトル画面の表示
	//DrawString((Game::kScreenWindth - GetDrawStringWidth(kExplanationText, -1)) / 2, 580, kExplanationText, GetColor(kColor, kColor, kColor));			//タイトル画面の表示
}
