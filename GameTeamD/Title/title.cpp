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

		SetLoopSamplePosSoundMem(109696, M.gTitleBGM);   //�Đ�����BGM�̃��[�v�ӏ��Ɏw��
		PlaySoundMem(M.gTitleBGM, DX_PLAYTYPE_LOOP);  //BGM���Đ��{���[�v

		t++;
	};

}