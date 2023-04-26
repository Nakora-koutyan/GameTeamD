#include<stdio.h>
#include<DxLib.h>
#include"Player.h"

void C_PLAYER::input()
{
	if (gNowKey & PAD_INPUT_LEFT)gPlayer_x--;
	if (gNowKey & PAD_INPUT_RIGHT)gPlayer_x++;

	DrawGraph(gPlayer_x,)
}
