#pragma once
#include "DxLib.h"

#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
	short ThumbX;	//�����l
};

class C_PLAYER
{
private:
	int gOldKey[BUTTONS];           // �O��̓��̓L�[
	int gNowKey;           // ����̓��̓L�[
	int gKeyFlg;           // ���̓L�[���


	int gPlayer_x;

	int gPlayerimages;
public:
	C_PLAYER()
	{
		gOldKey = 0;
		gNowKey = 0;
		gKeyFlg = 0;

		gPlayer_x = 640;
		gPlayerimages = LoadGraph("Material/Images/characterWalk02.png");
	}
	~C_PLAYER()
	{

	}
	void Update();
	void Draw() const;
};