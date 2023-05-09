#include"Player.h"
#include"../System/PadInput.h"
#include "math.h"

Player::Player()
{
	if (LoadDivGraph("Material/Images/Walk.png", 8, 8, 1, 160, 160, ImagesWalk) == -1)
	{
		throw"Material/Images/Walk.png";
	}

	//������
	TrunFlag = false;
	StickRollFlag = false;
	location.x = 100;
	location.y = 500;
	erea.width = 50;
	erea.height = 100;
	erea.width_rate = 0.6;
	erea.height_rate = 0.5;
	PlayerState = PLAYER_STATE::IDOL;
	speed = 0;
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;
	Image = ImageStand;


	//�t�H���g�̒ǉ�
	GuideFont = CreateFontToHandle("Guide", 24, 8, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

Player::~Player()
{
	//�t�H���g�̍폜
	DeleteFontToHandle(GuideFont);
}

void Player::UpDate()
{

}