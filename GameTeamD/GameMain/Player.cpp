#include<stdio.h>
#include<DxLib.h>
#include"Player.h"

void C_PLAYER::input()
{
	if (gPlayer.flg == TRUE) {
		if (gNowKey & PAD_INPUT_LEFT)gPlayer.x -= gPlayer.speed;
		if (gNowKey & PAD_INPUT_RIGHT)gPlayer.x += gPlayer.speed;
	}

}
