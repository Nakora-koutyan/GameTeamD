#include<stdio.h>
#include"DxLib.h"
#include"Title.h"
#include"../GameMain/GameMain.h"

TITLE::TITLE()
{
	// BGM読込
	gTitleBGM = LoadSoundMem("Material/Sounds/BGM/Title.wav");
	gCursor = LoadGraph("Material/Images/Apple_Red.png");
	gCursor_Move = LoadSoundMem("Material/Sounds/SE/cursor1.wav");
	gCursor_Enter = LoadSoundMem("Material/Sounds/SE/eats.wav");


	// gTitleBGMが流れてないなら流す
	if (CheckSoundMem(gTitleBGM) != 1 && gGameMode == E_TITLE)
	{
		SetLoopSamplePosSoundMem(109696, gTitleBGM);
		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	}

	gBackScreen = LoadGraph("Material/Images/Title.png");

}
TITLE::~TITLE()
{
	DeleteSoundMem(gTitleBGM);
}
	//for (int i = 0; i < 1;)
	//{
	//	// gTitleBGMが流れてないなら流す
	//	if (CheckSoundMem(gTitleBGM) != 1 && gGameMode == E_TITLE)
	//	{
	//		SetLoopSamplePosSoundMem(109696, gTitleBGM);
	//		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	//	}
	//	
	//}

	
	

//void TITLE::print()
//{
//	// ゲームモード(タイトル)
//	if (gGameMode == E_TITLE)
//	{
//		
//
//		DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
//
//	
//				/*while (vol > 0)
//				{
//					ClearDrawScreen();
//					DrawGraph(0, 0, gBackScreen, 0);
//					ChangeVolumeSoundMem(vol, gTitleBGM);
//					SetDrawBlendMode(DX_BLENDMODE_ALPHA, vol);
//					ScreenFlip();
//					vol--;
//					WaitTimer(9);
//				}
//				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);*/
//	
//
//		DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
//	}
//	if (gGameMode == E_TITLE) {
//		DrawFormatString(300, 10, 0xFFFFFF, "title");
//	}
//	// ゲームモード(メイン)
//	if (gGameMode == E_MAIN) {
//		DrawFormatString(300, 10, 0xFFFFFF, "main");
//		GAME_MAIN main;
//		main.main();
//	}
//	// ゲームモード(ランキング)
//	if (gGameMode == E_RANKING) {
//		DrawFormatString(300, 10, 0xFFFFFF, "rank");
//	}
//	if (gGameMode == E_HELP) {
//		DrawFormatString(300, 10, 0xFFFFFF, "help");
//	}
//	if (gGameMode == E_END) {
//		DrawFormatString(300, 10, 0xFFFFFF, "end");
//	}
//}
AbstractScene* TITLE::Update() {

	if (InputControl::TipLeftLStick(STICKL_Y) < -0.5) {
		if (++g_MenuNumber > 3) g_MenuNumber = 0;
		PlaySoundMem(gCursor_Move, DX_PLAYTYPE_BACK);
	}
	if (InputControl::TipLeftLStick(STICKL_Y) > 0.5) {
		if (--g_MenuNumber < 0) g_MenuNumber = 3;
		PlaySoundMem(gCursor_Move, DX_PLAYTYPE_BACK);
	}
	if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {	//Aボタンが押されたら真を返す
		while(vol > 0)
		{
			ClearDrawScreen();
			DrawGraph(0, 0, gBackScreen, 0);
			ChangeVolumeSoundMem(vol, gTitleBGM);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, vol);
			ScreenFlip();
			vol--;
			WaitTimer(9);
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		return new GameMain();		//返す値 ＝ ゲームメインシーン
	}
	return this;	//現在のシーンを返す(タイトル)
}

void TITLE::Draw() const {
	
	DrawGraph(0, 0, gBackScreen, 0);
	DrawString(300, 10, "title", 0xFFFFFF);
	DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
	DrawGraph(370, 300 + g_MenuNumber * 90, gCursor, 1);
}