#include"Player.h"
#include"../System/PadInput.h"
#include "math.h"

Player::Player()
{
	if (LoadDivGraph("Material/Images/Walk.png", 8, 8, 1, 160, 160, ImagesWalk) == -1)
	{
		throw"Material/Images/Walk.png";
	}

	//初期化
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


	//フォントの追加
	GuideFont = CreateFontToHandle("Guide", 24, 8, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

Player::~Player()
{
	//フォントの削除
	DeleteFontToHandle(GuideFont);
}

void Player::UpDate()
{

}