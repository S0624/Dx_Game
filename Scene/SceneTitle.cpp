#include"DxLib.h"
#include"SceneTitle.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "タイトル";
	const char* const kExplanationText = "1ボタンを押してください";
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
}

void SceneTitle::draw()
{
	DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//タイトル画面の表示
}
