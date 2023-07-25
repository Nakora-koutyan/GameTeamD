#include"Player.h"
#include"../System/Input.h"
#include"../System/PadInput.h"
#include <math.h>

PLAYER::PLAYER()
{
	//�摜�̓Ǎ�
	try
	{
		image_stand = LoadGraph("Material/Images/characterStand.png");		//Image�摜(����)�̓Ǎ�
		if (image_stand == -1)												//-1�����o���ꂽ��catch�փG���[���΂�
		{
			throw "Material/Images/characterStand.png";
		}

		LoadDivGraph("Material/Images/Dash.png", 6, 6, 1, 160, 160, images_dash);	//Image�摜6��(�_�b�V��)�̓Ǎ�
		for (int i = 0; i < 6; i++)													//-1�����o���ꂽ��catch�փG���[���΂�
		{
			if (images_dash[i] == -1)
			{
				throw"Material/Images/Dash.png";
			}
		}
		LoadDivGraph("Material/Images/walk.png", 8, 8, 1, 160, 160, images_walk);	//Image�摜8��(���s)�̓Ǎ�
		for (int i = 0; i < 8; i++)													//-1�����o���ꂽ��catch�փG���[���΂�
		{
			if (images_walk[i] == -1)
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
	location.y = 600;
	erea.width = 50;
	erea.height = 100;
	erea.width_rate = 0.6f;
	erea.height_rate = 0.5f;

	//�v���C���[�̏�Ԃ̏�����
	speed = 0;
	anim_timer = 0;
	anim_interval = 0;
	anim_type = 0;

	//�摜�̏�����
	image = image_stand;
	images_dash;
	images_walk;
	//location.x = 100;

	PlayerState ;
}

PLAYER::~PLAYER()		//�f�X�g���N�^
{
	//�t�H���g�̍폜
	DeleteFontToHandle(guide_font);
}

void PLAYER::PLAYER_DASH()
{
	MoveLeftDash();
	MoveRightDash();
	NotTip();					//�X�e�B�b�N������Ă鎞�̓���	
}

void PLAYER::MoveLeftDash()
{
	if (InputControl::TipLeftLStick(STICKL_X) < -0.7)
	{
		PlayerState = PLAYER_STATE::DASH;
		anim_interval = ANIMATION_INTERVAL;
		TurnFlag = true;

		if (speed > (-MAX_DASH_SPEED)) {
			speed += ((-PLAYER_DASH_SPEED) / 10);
		}
	}
}

void PLAYER::MoveRightDash()
{
	if (InputControl::TipLeftLStick(STICKL_X) > 0.7)
	{
		PlayerState = PLAYER_STATE::DASH;
		anim_interval = ANIMATION_INTERVAL;
		TurnFlag = false;

		if (speed < MAX_DASH_SPEED) {
			speed += (PLAYER_DASH_SPEED / 10);
		}
	}
}

void PLAYER::NotTip()
{
	if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
	{
		speed -= (speed * 0.05f);

		if (fabsf(speed) >= 1.0f)	//Speed�̒l���P�ȏ�5�����̎�
		{
			PlayerState = PLAYER_STATE::DASH;		//�v���C���[�̏�Ԃ��_�b�V���ɂ���
			anim_interval = ANIMATION_INTERVAL + 3;	//
		}
		else if (fabsf(speed) < 0)					//Speed�̒l���P�ȉ��̎�
		{
			anim_timer = 0;
			anim_type = 0;
			PlayerState = PLAYER_STATE::IDOL;
			image = image_stand;
			speed = 0;
		}
	}
}

void PLAYER::Update() //�L�����N�^�[�̈ړ��Ə�Ԃ̍X�V
{
	PLAYER_DASH();

	switch(PlayerState)
	{
	case PLAYER_STATE::IDOL:
		if (CheckSoundMem(walk_se) == 1)
		{
			StopSoundMem(walk_se);
		}
		if (CheckSoundMem(dash_se) == -1)
		{
			StopSoundMem(dash_se);
		}
		break;
	case PLAYER_STATE::DASH:
		if (CheckSoundMem(dash_se) == 1)
		{
			PlaySoundMem(walk_se, DX_PLAYTYPE_BACK, TRUE);
		}
		if (CheckSoundMem(dash_se) == 1)
		{
			StopSoundMem(dash_se);
		}
		DashAnimation();
		location.x += speed;

	}
}

void PLAYER::DashAnimation()
{
	if (anim_timer++ % anim_interval == 0)
	{
		image = images_dash[anim_type++ % 6];
	}
}

void PLAYER::Draw()const
{
	DrawRotaGraph((int)location.x, (int)location.y, 1.0, 0, image, TRUE, TurnFlag);	//��ʂɃv���C���[�̕\��
}

void PLAYER::Reset()
{
	TurnFlag = false;
	location.x = 100;
	location.y = 500;
	speed = 0;
	anim_timer = 0;
	anim_interval = 0;
	anim_type = 0;
	PlayerState = PLAYER_STATE::IDOL;
	image = image_stand;
}