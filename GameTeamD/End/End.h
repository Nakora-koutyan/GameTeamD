#pragma once
#include "AbstractScene.h"
class END:public AbstractScene
{
public:
	//�ϐ�
	static int E_count;
	static int E_second;

	//�摜�n���h���i�[�p�ϐ�
	static int mImageHandle;

	//�����o�֐�
	void End_Initialize();	//������
	void End_Finalize();	//�I��
	void End_Update();		//�X�V
	void End_Draw();		//�`��
};