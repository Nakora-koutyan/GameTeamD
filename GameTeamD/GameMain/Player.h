#pragma once
#include "../System/Collision.h"

#define BUTTONS 16
#define WALK_SPEED 3
#define DASH_SPEED 7
#define ANIMATION_INTERVAL 10

enum class PLAYER_STATE {
	IDOL = 0,
	WALK,
	DASH
};

class Player :public Collision
{
private:
	bool TrunFlag;
	bool stickRollFlag;
	PLAYER_STATE PlayerState; //�v���C���[�̌��݂̏�Ԃ𐧌�

	int ImageStand;		//�摜�p�ϐ�
	int ImageDamage;	//�摜�p�ϐ�
	int ImagesDash[6];	//�摜�p�z��
	int ImagesWalk[8];	//�摜�p�z��
	int Image;
	int AnimTimer;		//�摜�؂�ւ��p�^�C�}�[
	int AnimInterval;	//�A�j���[�V�����؂�ւ��̊Ԋu

	float Speed;


	int GuideFont;
	int DamageSE;
	int WalkSE;
	int DashSE;

private:
	void DashAnimation();
	void WalkAnimation();
	bool DamageAnimation();

public:
	//�R���X�g���N�^
	Player();

	//�f�X�g���N�^
	~Player();

	//�X�V
	void UpDate();

	//�`��
	void Draw()const;

	void Reset();
};