#pragma once
#include "DxLib.h"

/*�}�N����`*/
#define BUTTONS 16		//XINPUTpad�̃{�^����
#define STICKL_X 1		
#define STICKL_Y 2		
#define MAXL_X 32767.f  //���X�e�B�b�NX���̍ő�l(float�^)
#define MAXL_Y 32767.f  //���X�e�B�b�NY���̍ő�l(float�^)

class InputControl
{
public:
	static int key_flg;			//�ÓI�����o�ϐ�
	static int now_key;
	static int old_key;
	static XINPUT_STATE xinput;	//�����o�ϐ��̏�����

public:
	InputControl()		//�֐��̐錾
	{
		key_flg = 0;
		now_key = 0;
		old_key = 0;
	}

	static void Update();						//�X�V
	static int GetKey(int key);					//�L�[���擾
	static int GetKeyDown(int key);				//�L�[������Ԏ擾
	static int PressBotton(int Button);			//�L�[���͏��擾
	static float TipLeftLStick(short StickL);	//�X�e�B�b�N�c����擾
};