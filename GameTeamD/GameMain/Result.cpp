#include "Result.h"
#include "Dxlib.h"

//�R���X�g���N�^
RESULT::RESULT()
{
	ResultImg = LoadGraph("Material/Images/BackImage.png");
	FlmCnt = 0;
	second = 0;
}

//�f�X�g���N�^
RESULT::~RESULT()
{
	DeleteGraph(ResultImg);
}

void RESULT::Update()
{
	FlmCnt++;
	second = FlmCnt / 28;
	if (second >= 60)
	{
		//�X�R�A�������L���O�̍ŉ��ʈȏ�Ŗ��O����
		
		//�X�R�A�������L���O�̍ŉ��ʈȉ��Ń����L���O

	}
}

void RESULT::Draw() const
{
	//�w�i
	DrawGraph(0, 0, ResultImg, FALSE);
}

//�V�[���؂�ւ�
AbstractScene* RESULT::ChengeScene()
{

}