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
	enum class PLAYER_STATE
	{
		IDOL,
		DASH
	};

	//�v���C���[�̏�Ԑ錾
	PLAYER_STATE PlayerState;				//�v���C���[�̌��݂̏�Ԃ𐧌�

	//�v���C���[�摜�p�̔z��E�ϐ��錾
	int image_stand;					//�摜�p�ϐ�(����)
	int images_dash[6];				//�摜�p�z��(���s)
	int images_walk[8];				//�摜�p�z��(�_�b�V��)
	int image;						//�摜

	//�摜�؂�ւ��Ɋւ���ϐ��錾
	int anim_timer;					//�A�j���[�V�����摜�؂�ւ��p�^�C�}�[
	int anim_interval;				//�A�j���[�V�����؂�ւ��Ԋu
	int anim_type;					//�A�j���[�V�����^�C�v

	float speed;					//�v���C���[�̃X�s�[�h�l

	int walk_se;						//���sSE
	int dash_se;						//�_�b�V��SE
	int guide_font;

private:

	void PLAYER_DASH();				//�_�b�V������֐����܂Ƃ߂�ꏊ
	void MoveLeftDash();			//���_�b�V������
	void MoveRightDash();			//�E�_�b�V������
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