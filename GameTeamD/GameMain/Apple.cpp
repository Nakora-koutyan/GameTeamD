#include"Apple.h"

APPLE::APPLE()
{
	flg = FALSE;  // �_�~�[�f�[�^�i�g�p�j

	location.x =  0;  // �_�~�[�f�[�^�i���j
	location.y = 0;   // �_�~�[�f�[�^�i���j
	 erea.width = 63;     // �_�~�[�f�[�^�i���j
	 erea.height = 120;	 // �_�~�[�f�[�^�i���j
	 speed = 50; // �_�~�[�f�[�^�ispeed�j
	 point = 1;	 // �_�~�[�f�[�^�ipoint���Z�j
}

APPLE::~APPLE()
{

}

void APPLE::AppleControl(void)
{
	// �����S�̏����ݒ�
	if (flg == TRUE) 
	{
		// �^���������Ɉړ�
		location.y += speed;

		// Y����1000�ɂȂ��������
		if (location.y > 1000)
			flg = FALSE;
	}
}

void APPLE::Draw()const 
{
	if (flg == TRUE) {
		// �����S�̕\��
		DrawRotaGraph(location.x, location.y, 1, 0, img, TRUE);
	}
}