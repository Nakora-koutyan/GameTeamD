#pragma once
#include"DxLib.h"
#include"../System/Collision.h"

//�����l�ݒ�
#define PLAYER_WALK_SPEED	4		//���s�X�s�[�h�̏����l
#define PLAYER_DASH_SPEED	7		//�_�b�V���X�s�[�h�̏����l

//�v���C���[�̏������
#define PLAYER_STATE_IDOL	0		//�v���C���[�̒������
#define PLAYER_STATE_WALK	1		//�v���C���[�̕��s���
#define PLAYER_STATE_DASH	2		//�v���C���[�̃_�b�V�����

#define ANIMATION_INTERVAL 10		//�A�j���[�V�����؂�ւ��̊Ԋu

class PLAYER
{
private:
	enum PLAYER_STATE
	{
		IDOL = 0,
		WALK,
		DASH
	};

	//�v���C���[�̏�Ԑ錾
	int PlayerState;				//�v���C���[�̌��݂̏�Ԃ𐧌�

	//�v���C���[�摜�p�̔z��E�ϐ��錾
	int ImageStand;					//�����摜�p�ϐ�
	int ImagesDash[6];				//�_�b�V���摜�p�z��
	int ImagesWalk[8];				//���s�摜�p�z��
	int Image;						//�摜

	//�摜�؂�ւ��Ɋւ���ϐ��錾
	int AnimTimer;					//�A�j���[�V�����摜�؂�ւ��p�^�C�}�[
	int AnimInterval;				//�A�j���[�V�����؂�ւ��Ԋu
	int AnimType;					//�A�j���[�V�����^�C�v

	float speed;					//�v���C���[�̃X�s�[�h�l

private:

	void DashAnimation();			//���s�A�j���[�V����
	void WalkAnimation();			//���s�A�j���[�V����

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