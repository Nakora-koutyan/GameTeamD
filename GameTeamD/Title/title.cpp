#include<stdio.h>
#include<DxLib.h>
#include"Title.h"

int gMainbgm = LoadSoundMem("Material/Sounds/BGM/GameMain.wav");
int gBackScreen = LoadGraph("Material/Images/Title.png");

void TITLE::print()
{
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);
	DrawGraph(0, 0, gBackScreen, 0);
}