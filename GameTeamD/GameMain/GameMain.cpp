#include<stdio.h>
#include"DxLib.h"
#include"GameMain.h"

//GAME_MAIN::GAME_MAIN()
//{
//	// BGM“Ç
//	gMainBGM = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
//}
//
//GAME_MAIN::~GAME_MAIN()
//{
//	//DeleteSoundMem(gMainBGM);
//}
//
//void GAME_MAIN::main() {
//	// gMainBGM‚ª—¬‚ê‚Ä‚È‚¢‚È‚ç—¬‚·
//	if (CheckSoundMem(gMainBGM) != 1)
//	{
//		SetLoopSamplePosSoundMem(371945, gMainBGM);
//		PlaySoundMem(gMainBGM, DX_PLAYTYPE_BACK);
//		DrawFormatString(400, 10, 0xFFFFFF, "playd");
//		i++;
//		DrawFormatString(500, 10, 0xFFFFFF, "%d", i);
//		if (i > 500) i = 0;
//	}
//	DrawFormatString(700, 10, 0xFFFFFF, "%d", i);
//	i++;
AbstractScene* GameMain::Update() {
	int nInt;
	scanf_s("%d", &nInt);
	if (nInt == 1) {
		return nullptr;
	}
	return this;
}

void GameMain::Draw() const {
	printf("GameMain‚Å‚·B\n");
	printf("®”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢„");
}