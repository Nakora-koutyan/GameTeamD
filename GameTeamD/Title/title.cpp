#include<stdio.h>
#include<DxLib.h>
#include"Title.h"



void TITLE::print()
{	
	
	PlaySoundMem(gMainBGM, DX_PLAYTYPE_LOOP);
	DrawGraph(0, 0, gBackScreen, 0);
}