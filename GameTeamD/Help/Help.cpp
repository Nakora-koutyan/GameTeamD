#include "Help.h"
#include "Dxlib.h"
#include"../System/PadInput.h"
#include"../GameMain/GameMain.h"
#include"../Title/Title.h"

//�R���X�g���N�^
HELP::HELP()
{
	//�摜�̃��[�h
	//HelpImg=LoadGraph();
	sceneCHG = false;
	sceneFlg = 0;
};

//�X�V����
//void HELP::Update()
//{
//	//B�{�^�����͂ŃQ�[�����C����
//	if (InputControl::PressBotton(XINPUT_BUTTON_B))
//	{
//		sceneCHG = true;
//		sceneFlg = 1;
//	}
//	//A�{�^�����͂Ń^�C�g����
//	else if (InputControl::PressBotton(XINPUT_BUTTON_A))
//	{
//		sceneCHG = true;
//		sceneFlg = 2;
//	}
//};

//�`�揈��
//void HELP::Draw() const
//{
//
//
//	//�w�i
//	//DrawGraph(0,0,M.gHelpImg,FALSE);
//
//	//�������(��)
//	DrawString(0, 0, "�@�@�@�@�@�@�@��������@�@�@�@�@�@�@", GetColor(255, 0, 0));
//	DrawString(0, 20, "���X�e�B�b�N�Ńv���C���[���ړ�����", GetColor(255, 0, 0));
//	DrawString(0, 40, "�����Ă��郊���S���L���b�`���悤", GetColor(255, 0, 0));
//	DrawString(0, 60, "��������L���b�`���ă����L���O1�ʂ�ڎw��", GetColor(255, 0, 0));
//
//	//��ʑJ�ڕ��@���L��
//	DrawString(0, 80, "B�{�^�����͂ŃQ�[�����C����", GetColor(255, 0, 0));
//	DrawString(0, 100, "A�{�^�����͂Ń^�C�g����", GetColor(255, 0, 0));
//};

//�I������
//AbstractScene* HELP::ChangeScene()
//{
//	if (sceneCHG) 
//	{
//		if (sceneFlg == 1) 
//		{
//			return new GameMain;
//		}
//		if (sceneFlg == 2)
//		{
//			return new Title;
//		}
//	}
//
//	return this;
//
//};