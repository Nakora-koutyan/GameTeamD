#include "Help.h"
#include "Dxlib.h"

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
	//�w�i
	//DrawGraph(0,0,mImageHandle,FALSE);

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