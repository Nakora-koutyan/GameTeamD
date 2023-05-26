#include<stdio.h>
#include"DxLib.h"
#include"Title.h"
#include"../GameMain/GameMain.h"

TITLE::TITLE()
{
	// BGM�Ǎ�
	gTitleBGM = LoadSoundMem("Material/Sounds/BGM/Title.wav");
	gCursor = LoadGraph("Material/Images/Apple_Red.png");
	gCursor_Move = LoadSoundMem("Material/Sounds/SE/cursor1.wav");
	gCursor_Enter = LoadSoundMem("Material/Sounds/SE/eats.wav");


	// gTitleBGM������ĂȂ��Ȃ痬��
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
	//	// gTitleBGM������ĂȂ��Ȃ痬��
	//	if (CheckSoundMem(gTitleBGM) != 1 && gGameMode == E_TITLE)
	//	{
	//		SetLoopSamplePosSoundMem(109696, gTitleBGM);
	//		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	//	}
	//	
	//}

	
	

//void TITLE::print()
//{
//	// �Q�[�����[�h(�^�C�g��)
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
//	// �Q�[�����[�h(���C��)
//	if (gGameMode == E_MAIN) {
//		DrawFormatString(300, 10, 0xFFFFFF, "main");
//		GAME_MAIN main;
//		main.main();
//	}
//	// �Q�[�����[�h(�����L���O)
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
	if (InputControl::PressBotton(XINPUT_BUTTON_A) == true) {	//A�{�^���������ꂽ��^��Ԃ�
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
		return new GameMain();		//�Ԃ��l �� �Q�[�����C���V�[��
	}
	return this;	//���݂̃V�[����Ԃ�(�^�C�g��)
}

void TITLE::Draw() const {
	
	DrawGraph(0, 0, gBackScreen, 0);
	DrawString(300, 10, "title", 0xFFFFFF);
	DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
	DrawGraph(370, 300 + g_MenuNumber * 90, gCursor, 1);
}