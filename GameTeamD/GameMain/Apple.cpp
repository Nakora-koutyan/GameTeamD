#include<stdio.h>
#include"DxLib.h"
#include"Apple.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	DrawCircle(30, 30, 10, 0xff0000, TRUE);
	DrawCircle(30, 30, 10, 0x00ff00, TRUE);
	DrawCircle(30, 30, 10, 0xffd700, TRUE);
	DrawCircle(30, 30, 10, 0xff00ff, TRUE);

}


