#include "Help.h"
#include "Dxlib.h"
<<<<<<< HEAD
#include"../System/Input.h"
=======
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)

//����������
void HELP::HELP_Initialize()
{
	//�摜�̃��[�h
	//mImageHandle=LoadGraph();
};

//�X�V����
void HELP::HELP_Update()
{
	//B�{�^�����͂ŃQ�[�����C����

	//A�{�^�����͂Ń^�C�g����

};

//�`�揈��
void HELP::HELP_Draw()
{

<<<<<<< HEAD
	M_INPUT M{};

	M.Input();

	//�w�i
	DrawGraph(0,0,M.gHelpImg,FALSE);
=======

	//�w�i
	//DrawGraph(0,0,M.gHelpImg,FALSE);
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)

	//�������(��)
	DrawString(0, 0, "�@�@�@�@�@�@�@��������@�@�@�@�@�@�@", GetColor(255, 0, 0));
	DrawString(0, 20, "���X�e�B�b�N�Ńv���C���[���ړ�����", GetColor(255, 0, 0));
	DrawString(0, 40, "�����Ă��郊���S���L���b�`���悤", GetColor(255, 0, 0));
	DrawString(0, 60, "��������L���b�`���ă����L���O1�ʂ�ڎw��", GetColor(255, 0, 0));

	//��ʑJ�ڕ��@���L��
	DrawString(0, 80, "B�{�^�����͂ŃQ�[�����C����", GetColor(255, 0, 0));
	DrawString(0, 100, "A�{�^�����͂Ń^�C�g����", GetColor(255, 0, 0));
};

//�I������
void HELP::HELP_Finalize()
{
	//�摜�̉��
	//DeleteGraph(mImageHandle);
};