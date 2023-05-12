#include<stdio.h>
#include"DxLib.h"
#include"Title.h"
#include"../System/Input.h"



void TITLE::print()
{
	if (t == 0)
	{

		M_INPUT M;

		M.Input();

		SetLoopSamplePosSoundMem(109696, M.gTitleBGM);   //再生するBGMのループ箇所に指定
		PlaySoundMem(M.gTitleBGM, DX_PLAYTYPE_LOOP);  //BGMを再生＋ループ

		t++;
	};

}