#include "PadInput.h"
#include"DxLib.h"

//�֐��̒�`
XINPUT_STATE InputControl::xinput;
int InputControl::key_flg;
int InputControl::now_key;
int InputControl::old_key;

void InputControl::Update() //�L�[���͏��X�V
{
	old_key = now_key;
	now_key = GetJoypadXInputState(DX_INPUT_PAD1,&xinput);
	key_flg = now_key & ~old_key; //����������(2�t���[���ȏ�Ǎ��̋���)
}

int InputControl::GetKey(int key) //���������e
{
	if (now_key & key)
	{
		return TRUE;
	}

	return FALSE;
}

int InputControl::GetKeyDown(int key) //���������� //�L�[����ԔF��
{
	if (key_flg & key)
	{
		return TRUE;
	}

	return FALSE;
}
int InputControl::PressBotton(int Button)//�{�^�����͏�ԔF��
{
	int OnPress = xinput.Buttons[Button];

	return OnPress;
}
//�X�e�B�b�N�̌X������
float InputControl::TipLeftLStick(short StickL) 
{
	if (StickL == STICKL_X)
	{
		float ratioL_X = xinput.ThumbLX / MAXL_X;

		//���X�e�B�b�N�̉������ő�l��1�Ƃ�������
		return ratioL_X;
	}
	else if(StickL == STICKL_Y)
	{
		float ratioL_Y = xinput.ThumbLY / MAXL_Y;

		//���X�e�B�b�N�̏c�����ő�l��1�Ƃ�������
		return ratioL_Y;
	}

	return 0;
}