#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"
#include"../Title/title.h"
#include "../System/Input.h"

GameMain::GameMain()
{
	// BGM読込
	gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
	gGameBackScreen = LoadGraph("Material/Images/BackImage.png");

	// gMainBGMが流れてないなら流す
	if (CheckSoundMem(gMainBGM) != 1)
	{
		SetLoopSamplePosSoundMem(371945, gMainBGM);
		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
	}

}

GameMain::~GameMain()	//デストラクタ
{
	DeleteSoundMem(gMainBGM);
}


AbstractScene* GameMain::Update() //ゲームメインのアップデート
{
	player.Update();	//プレイヤーの更新




	//if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {
	//	return new TITLE;	//
	//}

	return this;	//現在のシーンを返す(ゲームメイン)
}

void GameMain::Draw() const {
	DrawString(300, 10, "GameMain", 0xFFFFFF);
	DrawGraph(0, 0, gGameBackScreen,0);
	player.Draw();
	DrawFormatString(100, 100, 0xffffff, "%f", player.Speed);
}