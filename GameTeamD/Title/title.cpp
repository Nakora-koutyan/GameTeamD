#include<stdio.h>
#include<DxLib.h>
#include"Title.h"

int gMainbgm;

void TITLE::print()
{
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);
}