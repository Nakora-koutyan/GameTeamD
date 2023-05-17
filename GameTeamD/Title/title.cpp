#include<stdio.h>
#include"DxLib.h"
#include"Title.h"

void TITLE::print()
{	
	if (CheckSoundMem(gTitleBGM) != 1)
	{
		SetLoopSamplePosSoundMem(109696, gTitleBGM);
		PlaySoundMem(gTitleBGM, DX_PLAYTYPE_LOOP);
	}

	if (GetKey(PAD_INPUT_DOWN)) {
		if (++g_MenuNumber > 3) g_MenuNumber = 0;
		DrawBox(300, 300, 400, 400, 0xFFFFFF, 1);
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	if (GetKey(PAD_INPUT_UP)) {
		if (--g_MenuNumber < 0) g_MenuNumber = 2;
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	
	DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
}