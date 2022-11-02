#include"DxLib.h"
#include"SceneResult.h"
#include"Pad.h"

namespace
{
	const char* const kTitleText = "リザルト";
	const char* const kExplanationText = "1ボタンを押してください";
}
SceneResult::SceneResult() :
	m_isEnd(-1)
{

}

void SceneResult::update()
{
	if (Pad::isTrigger(PAD_INPUT_1))
	{
		m_isEnd = true;					//mainに切り替え
	}
}

void SceneResult::draw()
{
	DrawString(620, 480, kTitleText, GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString(620, 580, kExplanationText, GetColor(255, 255, 255));			//タイトル画面の表示
}
