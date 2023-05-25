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
	//int x, y, w, h;  // ���W�A���A����
	float speed;       // �ړ����x
	int point;       // �X�R�A���Z�|�C���g
	float magnification; // �����蔻��̔{��
public:

	APPLE();

	int gAppleImg[4];

	void AppleControl(); // �����S�̈ړ�����
	//int CreateApple();   // �����S�̐�������
	//int AppleProd();     // �����S�̐�����
	//int IMAGES_RINGO();              // �����S�̉摜�\������
	//void AppleSetting();

	~APPLE();
};

