#pragma once
#include<stdio.h>
#include"../System/Input.h"
#include"DxLib.h"

class APPLE
{
public:

	APPLE();

	int gAppleImg[4];

	void AppleControl(); // �����S�̈ړ�����
	int CreateApple();   // �����S�̐�������
	int AppleProd();     // �����S�̐�����
	int IMAGES_RINGO();              // �����S�̉摜�\������
	void AppleSetting();

	~APPLE();
};

