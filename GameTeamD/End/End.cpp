#include "End.h"
#include "Dxlib.h"


int END::E_count;
int END::E_second;
int END::mImageHandle;
//������
void END::End_Initialize()
{
	float E_count = 0;	//�t���[���J�E���g
	float E_second = 0;	//�b��

	//�摜�̃��[�h
	//mImageHandle=LoadGraph();
};

//�X�V
void END::End_Update()
{
	//E_count��1�t���[�����Ƃɉ��Z
	E_count++;

	//E_count�̒l��b�ɂ��Ď擾
	E_second = E_count / 60;

	//5�b�o�ƏI��(gGameMode��E_CLOSE�ɕύX)
	if (E_second == 5)
	{
		
	}

};

//�`��
void END::End_Draw()
{


	//�w�i
	//DrawGraph(0,0, M.gEndImg, FALSE);

	//����
	DrawString(0, 0, "Thank you for playing", GetColor(255, 0, 0));

	//�N���W�b�g�i�f�ނ̗��p�����Ȃǁj

};

//�I��
void END::End_Finalize()
{
	//�摜�̉��(�v��Ȃ�����)
	//DeleteGraph(mImageHandle);
};