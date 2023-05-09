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

		SetLoopSamplePosSoundMem(109696, M.gTitle);   //再生するBGMのループ箇所に指定
		PlaySoundMem(M.gTitleBGM, DX_PLAYTYPE_LOOP);  //BGMを再生＋ループ

		i++;
	};
}