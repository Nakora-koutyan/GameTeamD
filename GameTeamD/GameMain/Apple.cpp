#include"Apple.h"
#define APPLE_MAX 10

struct RINGO {
	int flg;        // �g�p�t���O
	int type;       // �^�C�v
	int img;         // �摜
	int x, y, w, h;  // ���W�A���A����
	int speed;       // �ړ����x
	int point;       // �X�R�A���Z�|�C���g

};

struct RINGO gApple[APPLE_MAX];
struct RINGO gApple00 = { TRUE,0,0,50,50,63,120,50,1 };
struct RINGO gAppleCn = { TRUE,3,0,100,-50,18,18,10,1 };


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
	gAppleImg[0] = LoadGraph("Material/Images/Apple_Red.png");
	gAppleImg[1] = LoadGraph("Material/Images/Apple_Green.png");
	gAppleImg[2] = LoadGraph("Material/Images/Apple_Gold.png");
	gAppleImg[3] = LoadGraph("Material/Images/Apple_Poison.png");

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
	for (int i = 0; i < 4; i++)
	{
		DeleteGraph(gAppleImg[i]);
	}
}

void APPLE::AppleControl(void)
{
	//this;

	
	// �����S�̏����ݒ�
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == TRUE) {

			//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);

			// �����S�̕\��
			DrawGraph(gApple[i].x, gApple[i].y, gApple[i].img, TRUE);

			// �^���������Ɉړ�
			gApple[i].y += gApple[i].speed;

			// Y����1000�ɂȂ��������
			if (gApple[i].y > 1000)
				gApple[i].flg = FALSE;
		}
	}
	CreateApple();
}

int APPLE::CreateApple()
{

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gApple00;
			gApple[i].type = AppleProd();
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(6) * 150 + 100;

			switch (gApple[i].type)
	        {
	        case 0:
		           // �ԃ����S�o��
		           gApple[i].speed = 1;
		     break;

			case 1:
					// �����S�o��
					gApple[i].speed = 3;
			break;

			case 2:
					// �������S�o��
					gApple[i].speed = 5;
			break;

			case 3:
					// �Ń����S�o��
					gApple[i].speed = 0.5;
			break;
	        }

			
			// ����
		return TRUE;
		}
	}
			
	// ���s
	return FALSE;
}

int APPLE::AppleProd()     // �����S�̐�����
{

	int rand = GetRand(19);
	if (rand < 11) {
		return 0;
	}
	else if (rand < 16) {
		return 1;
	}
	else if (rand < 18) {
		return 2;
	}
	else {
		return 3;
	}
}
