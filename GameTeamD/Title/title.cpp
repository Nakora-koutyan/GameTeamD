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

		SetLoopSamplePosSoundMem(109696, M.gTitle);   //�Đ�����BGM�̃��[�v�ӏ��Ɏw��
		PlaySoundMem(M.gTitleBGM, DX_PLAYTYPE_LOOP);  //BGM���Đ��{���[�v

		i++;
	};
}