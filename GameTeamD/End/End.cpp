#include "End.h"
#include "Dxlib.h"
#include"../System/Input.h"

int END::End;

//������
END::END()
{
	End = 0;
	Count = 0;

	//�摜�̃��[�h
	//Endimg=LoadGraph();
};

//SceneManager�p
//�X�V
//void END::Update()
//{
//	//5�b�o�ƏI��(gGameMode��E_CLOSE�ɕύX)
//	if (300 < Count++)
//	{
//		End = 99;
//	}
//};

//�`��
//void END::Draw() const
//{
//
//	M_INPUT M{};
//
//	M.Input();
//
//	//�w�i
//	DrawGraph(0,0, M.gEndImg, FALSE);
//
//	//����
//	DrawString(0, 0, "Thank you for playing", GetColor(255, 0, 0));
//
//	//�N���W�b�g�i�f�ނ̗��p�����Ȃǁj
//
//};

//SceneManager�p
//AbstractScene* END::ChangeScene()
//{
//	return this;
//};