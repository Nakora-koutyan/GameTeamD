#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
public:

	APPLE();

	void AppleControl(); // �����S�̈ړ�����
	int CreateApple();   // �����S�̐�������
	int AppleProd();     // �����S�̐�����
	int gAppleImg[4];
	//int IMAGES_RINGO();              // �����S�̉摜�\������
	//void AppleSetting();

	~APPLE();
};

