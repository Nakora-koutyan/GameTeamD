#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"../System/Collision.h"
#include"DxLib.h"
#define APPLE_MAX 10

struct RINGO {
	int flg;        // �g�p�t���O
	int type;       // �^�C�v
	int img;         // �摜
	int x, y, w, h;  // ���W�A���A����
	int speed;       // �ړ����x
	int point;       // �X�R�A���Z�|�C���g
};

class APPLE : public BoxCollider
{
public:
	int flg;        // �g�p�t���O
	int type;       // �^�C�v
	int img;         // �摜
	int point;       // �X�R�A���Z�|�C���g
	int gAppleImg[4];

	float speed;       // �ړ����x
	float magnification; // �����蔻��̔{��

	APPLE();
	~APPLE();

	void AppleControl(); // �����S�̈ړ�����
	void Draw()const;
};

