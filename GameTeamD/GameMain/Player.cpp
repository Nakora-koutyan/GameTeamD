#include"DxLib.h"
#include"Player.h"

void C_PLAYER::Update()
{
	
}

void C_PLAYER::Draw() const
{
	DrawGraph(0, 0, gPlayerimages, TRUE);
	DrawBox(640, 200, 640 + 200, 400, 0xffffffff, TRUE);
}
