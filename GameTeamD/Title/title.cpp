#include<stdio.h>
#include"DxLib.h"
#include"Title.h"

void TITLE::print()
{	
	if (GetKeyDown(PAD_INPUT_A)) {
		if (++g_MenuNumber > 3) g_MenuNumber = 0;
		DrawBox(300, 300, 400, 400, 0xFFFFFF, 1);
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	if (GetKey(PAD_INPUT_UP)) {
		if (--g_MenuNumber < 0) g_MenuNumber = 2;
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	//PlaySoundMem(gMainBGM, DX_PLAYTYPE_LOOP);
	DrawFormatString(200, 10, 0xFFFFFF, "%d", g_MenuNumber);
}