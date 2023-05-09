#include<stdio.h>
#include"DxLib.h"
#include"Title.h"
#include"../System/Input.h"


void TITLE::print()
{
	if (i == 0)
	{

		M_INPUT M;

		M.Input();

		SetLoopSamplePosSoundMem(109696, M.gTitleBGM);
		PlaySoundMem(M.gTitleBGM, DX_PLAYTYPE_LOOP);

		i++;
	};
}