#include"Apple.h"


//
//struct RINGO gApple[APPLE_MAX];
//struct RINGO gApple00 = { TRUE,0,0,50,50,63,120,50,1 };
//struct RINGO gAppleCn = { TRUE,3,0,100,-50,18,18,10,1 };


//struct RINGO gApple[APPLE_MAX]{};

//int APPLE::IMAGES_RINGO()
//{
//	M_INPUT M{};
//
//	M.Input();
//
//	DrawGraph(100, 200, M.gAppleImg[0], TRUE);
//	DrawGraph(200, 200, M.gAppleImg[1], TRUE);
//	DrawGraph(300, 200, M.gAppleImg[2], TRUE);
//	DrawGraph(400, 200, M.gAppleImg[3], TRUE);
//
//	
//	/*int red, blue, gold, poison;
//	red = DrawCircle(0, 0, 80, 0xff0000, TRUE);
//	blue = DrawCircle(100, 100, 80, 0x00ff00, TRUE);
//	gold = DrawCircle(200, 200, 80, 0xffd700, TRUE);
//	poison = DrawCircle(300, 300, 80, 0xff00ff, TRUE);
//	*/
//
//	// AppleControl();
//	
//	return 0;
//}
APPLE::APPLE()
{
	flg = FALSE;  // �_�~�[�f�[�^�i�g�p�j

	location.x =  0;  // �_�~�[�f�[�^�i���j
	location.y = 0;   // �_�~�[�f�[�^�i���j
	 erea.width = 63;     // �_�~�[�f�[�^�i���j
	 erea.height = 120;	 // �_�~�[�f�[�^�i���j
	 speed = 50; // �_�~�[�f�[�^�ispeed�j
	 point = 1;	 // �_�~�[�f�[�^�ipoint���Z�j

	//// �����S�̏����ݒ�
	//for (int i = 0; i < APPLE_MAX; i++) {
	//	if (gApple[i].flg == TRUE) {

	//		//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);

	//		// �����S�̕\��
	//		DrawGraph(gApple[i].x, gApple[i].y, gApple[i].img, TRUE);

	//		// �^���������Ɉړ�
	//		gApple[i].y += gApple[i].speed;

	//		// Y����1000�ɂȂ��������
	//		if (gApple[i].y > 1000)
	//			gApple[i].flg = FALSE;
	//	}
	//}
}

APPLE::~APPLE()
{

}

void APPLE::AppleControl(void)
{
	//this;


	// �����S�̏����ݒ�

	if (flg == TRUE) {

		//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);



		// �^���������Ɉړ�
		location.y += speed;

		// Y����1000�ɂȂ��������
		if (location.y > 1000)
			flg = FALSE;

	}
}

void APPLE::Draw()const {
	if (flg == TRUE) {
		// �����S�̕\��
		DrawRotaGraph(location.x, location.y, 1, 0, img, TRUE);
	}
}

