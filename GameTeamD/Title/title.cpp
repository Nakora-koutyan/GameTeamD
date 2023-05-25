#include<stdio.h>
#include"DxLib.h"
#include"Title.h"
#include"../GameMain/GameMain.h"

TITLE::TITLE()
{
	gBackScreen = LoadGraph("Material/Images/Title.png");
	gTitleBGM = LoadSoundMem("Material/Sounds/BGM/Title.wav");
	gCursor_Move = LoadSoundMem("Material/Sounds/SE/cursor1.wav");
	gCursor_Enter = LoadSoundMem("Material/Sounds/SE/eats.wav");
	// gTitleBGMが流れてないなら流す
	if (CheckSoundMem(gTitleBGM) != 1 && gGameMode == E_TITLE)
	{
		SetLoopSamplePosSoundMem(109696, gTitleBGM);
		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	}
	

}
TITLE::~TITLE()
{
	DeleteSoundMem(gTitleBGM);
}

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
	if (g_MenuNumber == 1) {
		return new GameMain();
	}
	return this;
}

void TITLE::Draw() const {
	DrawGraph(0, 0, gBackScreen, 0);
	DrawFormatString(300, 10, 0xFFFFFF, "title");
}