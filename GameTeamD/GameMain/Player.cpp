#include<stdio.h>
#include"DxLib.h"
#include"Player.h"

int G_PLAYER::PlayerImages()
{
	int Color;

	Color = GetColor(0, 0, 255);//�F�̒l���擾

	DrawBox(0, 0, 64, 48, Color, TRUE);

	return 0;
}