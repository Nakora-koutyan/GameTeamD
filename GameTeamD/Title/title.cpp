#include<stdio.h>
#include"DxLib.h"
#include"Title.h"



void TITLE::print()
{	
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++g_MenuNumber > 3) g_MenuNumber = 0;
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--g_MenuNumber < 0) g_MenuNumber = 2;
		//PlaySoundMem(Menu1, DX_PLAYTYPE_BACK);
	}
	//PlaySoundMem(gMainBGM, DX_PLAYTYPE_LOOP);

}