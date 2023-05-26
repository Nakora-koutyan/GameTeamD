#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include <math.h>

PLAYER::PLAYER()
{
	//�摜�̓Ǎ�
	try 
	{
		ImageStand = LoadGraph("Material/Images/characterStand.png");		//Image�摜(����)�̓Ǎ�
		if (ImageStand == -1)												//-1�����o���ꂽ��catch�փG���[���΂�
		{
			throw "Material/Images/characterStand.png";
		}

		LoadDivGraph("Material/Images/Dash.png", 6, 6, 1, 160, 160, ImagesDash);	//Image�摜6��(�_�b�V��)�̓Ǎ�
		for (int i = 0; i < 6; i++)													//-1�����o���ꂽ��catch�փG���[���΂�
		{
			if (ImagesDash[i] == -1)
			{
				throw"Material/Images/Dash.png";							
			}
		}
		LoadDivGraph("Material/Images/walk.png", 8, 8, 1, 160, 160, ImagesWalk);	//Image�摜8��(���s)�̓Ǎ�
		for (int i = 0; i < 8; i++)													//-1�����o���ꂽ��catch�փG���[���΂�
		{	
			if (ImagesWalk[i] == -1)
			{
				throw"Material/Images/walk.png";
			}
		}
	}
	catch (int& err) {
		printf("�G���[�R�[�h%d\n", err);		//�G���[�̕\��
	}

	TurnFlag = false;

	//�v���C���[�����蔻��̒l�̏�����
	location.x = 100;
	location.y = 500;
	erea.width = 50;
	erea.height = 100;
	erea.width_rate = 0.6;
	erea.height_rate = 0.5;

	//�v���C���[�̏�Ԃ̏�����
	PlayerState = PLAYER_STATE::IDOL;
	Speed = 0;
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;

	//�摜�̏�����
	Image = ImageStand;
	ImagesDash;
	//location.x = 100;
}

PLAYER::~PLAYER()		//�f�X�g���N�^
{
	//�t�H���g�̍폜
	DeleteFontToHandle(GuideFont);
}

void PLAYER::Update() //�L�����N�^�[�̈ړ��Ə�Ԃ̍X�V
{
	
	MoveLeftDash();

	MoveRightDash();

	switch(PlayerState)
	{
	case PLAYER_STATE::IDOL:
		if (CheckSoundMem(WalkSE) == 1)
		{
			StopSoundMem(WalkSE);
		}
		if (CheckSoundMem(DashSE) == -1)
		{
			StopSoundMem(DashSE);
		}
		break;
	case PLAYER_STATE::WALK:
		if (CheckSoundMem(DashSE) == 1)
		{
			PlaySoundMem(WalkSE,DX_PLAYTYPE_BACK,TRUE);
		}
		if (CheckSoundMem(DashSE) == 1)
		{
			StopSoundMem(DashSE);
		}
		WalkAnimation();
		location.x += Speed;
		break;
	case PLAYER_STATE::DASH:
		if (CheckSoundMem(DashSE) == 1)
		{
			PlaySoundMem(WalkSE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (CheckSoundMem(DashSE) == 1)
		{
			StopSoundMem(DashSE);
		}
		DashAnimation();
		location.x += Speed;
		break;

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

void PLAYER::Draw()const
{
	DrawRotaGraph(location.x, location.y, 1.0, 0, Image, TRUE, TurnFlag);	//��ʂɃv���C���[�̕\��
}

void PLAYER::Reset()
{
	TurnFlag = false;
	location.x = 100;
	location.y = 500;
	Speed = 0;
	AnimTimer = 0;
	AnimInterval = 0;
	AnimType = 0;
	PlayerState = PLAYER_STATE::IDOL;
	Image = ImageStand;
}