#include<stdio.h>
#include"DxLib.h"
#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"

struct CHARACTOR {
	int flg;
	int type;
	int img;
	int x, y, w, h;
	int speed;
};

PLAYER::PLAYER()	//�R���X�g���N�^(������)
{
	gPlayerImg = LoadGraph("Material/Images/characterWalk02.png");
}

void PLAYER::IMAGES_PLAYER() //�摜�̕\��
{
	DrawGraph(550, 500, gPlayerImg,TRUE);
}

void PLAYER::Move() //�L�����N�^�[���[�u
{
	
}