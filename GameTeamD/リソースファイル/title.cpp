#include<stdio.h>
#include<DxLib.h>
#include"title.h"

int gMainbgm;

void TITLE::print()
{
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);
}