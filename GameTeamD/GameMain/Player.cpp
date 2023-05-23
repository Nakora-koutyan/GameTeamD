#include<stdio.h>
#include"DxLib.h"
#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include"math.h"

PLAYER::PLAYER()
{
	//������
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;
	Image = ImageStand;
	ImagesDash;
	location.x = 100;
}

PLAYER::~PLAYER()
{

}
void PLAYER::Update() //�L�����N�^�[�̈ړ��Ə�Ԃ̍X�V
{
	//�X�e�B�b�N�̌X������ > 5��
	if (InputControl::TipLeftLStick(STICKL_X) > 0.5)
	{
		//5���ȏ�

	}
}

void PLAYER::DashAnimation()
{

	if (AnimTimer++ % AnimInterval == 0)
	{
		Image = ImagesDash[AnimType++ % 6];
	}
}
void PLAYER::WalkAnimation()
{
	if (AnimTimer++ % AnimInterval == 0)
	{
		Image = ImagesWalk[AnimType++ % 8];
	}
}