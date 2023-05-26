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

	void PLAYER_DASH();					//�_�b�V������֐����܂Ƃ߂�ꏊ

	void MoveLeftDash();			//������
	void MoveRightDash();			//�E����
	void NotTip();					//�X�e�B�b�N������Ă鎞�̓���

	void DashAnimation();			//���s�A�j���[�V����

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