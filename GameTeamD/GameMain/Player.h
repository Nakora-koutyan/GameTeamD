#pragma once
#include"DxLib.h"
#include"../System/Collision.h"
#include"../System/PadInput.h"

#include<math.h>

//�����l�ݒ�
#define PLAYER_WALK_SPEED	4		//���s�X�s�[�h�̏����l
#define PLAYER_DASH_SPEED	10.0f	//�_�b�V���X�s�[�h�̏����l
#define MAX_DASH_SPEED		5		//

//�v���C���[�̏������
#define PLAYER_STATE_IDOL	0		//�v���C���[�̒������
#define PLAYER_STATE_WALK	1		//�v���C���[�̕��s���
#define PLAYER_STATE_DASH	2		//�v���C���[�̃_�b�V�����

#define ANIMATION_INTERVAL	3		//�A�j���[�V�����؂�ւ��̊Ԋu

class PLAYER:public BoxCollider
{
public:
	int TurnFlag;
	enum PLAYER_STATE
	{
		IDOL = 0,
		WALK,
		DASH
	};

	//�v���C���[�̏�Ԑ錾
	PLAYER_STATE PlayerState;				//�v���C���[�̌��݂̏�Ԃ𐧌�

	//�v���C���[�摜�p�̔z��E�ϐ��錾
	int ImageStand;					//�摜�p�ϐ�(����)
	int ImagesDash[6];				//�摜�p�z��(���s)
	int ImagesWalk[8];				//�摜�p�z��(�_�b�V��)
	int Image;						//�摜

	//�摜�؂�ւ��Ɋւ���ϐ��錾
	int AnimTimer;					//�A�j���[�V�����摜�؂�ւ��p�^�C�}�[
	int AnimInterval;				//�A�j���[�V�����؂�ւ��Ԋu
	int AnimType;					//�A�j���[�V�����^�C�v

	float Speed;					//�v���C���[�̃X�s�[�h�l

	int WalkSE;						//���sSE
	int DashSE;						//�_�b�V��SE
	int GuideFont;

private:

	void DashAnimation();			//���s�A�j���[�V����
	void WalkAnimation();			//���s�A�j���[�V����


private:
	//�X�e�B�b�N�̓���ɔ����L�����N�^�[�̈ړ������ƃ_�b�V��
	void MoveLeftDash()
	{
		if (InputControl::TipLeftLStick(STICKL_X) < -0.7)
		{
			PlayerState = PLAYER_STATE::DASH;
			AnimInterval = ANIMATION_INTERVAL;
			TurnFlag = true;
			
			if (Speed > ( - 1 * MAX_DASH_SPEED)) {
				Speed += ((- 1 * PLAYER_DASH_SPEED) / 10);
			}
		}
		else if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
		{
			Speed += (Speed * 0.3);
			TurnFlag = true;


			if (InputControl::TipLeftLStick(STICKL_X) > 0 || InputControl::TipLeftLStick(STICKL_X) == 0)
			{
				TurnFlag = true;
				if (fabsf(Speed) > 1 && fabsf(Speed) < 5)
				{
					PlayerState = PLAYER_STATE::DASH;
					AnimInterval = ANIMATION_INTERVAL + 1;
					TurnFlag = true;
				}
				else if (fabsf(Speed) < 1)
				{
					AnimTimer = 0;
					AnimType = 0;
					PlayerState = PLAYER_STATE::IDOL;
					Image = ImageStand;
					TurnFlag = true;
				}
			}
		}
	}

	void MoveRightDash() 
	{
		if (InputControl::TipLeftLStick(STICKL_X) > 0.7)
		{
			PlayerState = PLAYER_STATE::DASH;
			AnimInterval = ANIMATION_INTERVAL;
			TurnFlag = false;


			if (Speed < MAX_DASH_SPEED) {
				Speed += (PLAYER_DASH_SPEED / 10);
			}
		}
		else if (InputControl::TipLeftLStick(STICKL_X) > -0.3 && InputControl::TipLeftLStick(STICKL_X) < 0.3)
		{
			Speed -= (Speed * 0.3);
			TurnFlag = false;

			if (InputControl::TipLeftLStick(STICKL_X) < 0 || InputControl::TipLeftLStick(STICKL_X) == 0) 
			{
				TurnFlag = false;
				if (fabsf(Speed) > 1 && fabsf(Speed) < 5)	//Speed�̒l���P�ȏ�5�����̎�
				{
					PlayerState = PLAYER_STATE::DASH;		//�v���C���[�̏�Ԃ��_�b�V���ɂ���
					AnimInterval = ANIMATION_INTERVAL + 1;	//
				}
				else if (fabsf(Speed) < 1)					//Speed�̒l���P�ȉ��̎�
				{
					AnimTimer = 0;
					AnimType = 0;
					PlayerState = PLAYER_STATE::IDOL;
					Image = ImageStand;
				}
			}
		}
	}


public:
	//�R���X�g���N�^
	PLAYER();

	//�f�X�g���N�^
	~PLAYER();

	//�v���C���[�̌��݂̏�Ԃ̍X�V
	void Update();

	//�`��
	void Draw() const;

	//��Ԃ̃��Z�b�g
	void Reset();
;
};