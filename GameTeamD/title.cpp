#include<stdio.h>
#include<DxLib.h>
#include"../GameTeamD/Title/title.h"

int gMainbgm;

void TITLE::print()
{
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);
}