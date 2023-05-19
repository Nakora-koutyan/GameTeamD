#include"Apple.h"
#include"../System/Input.h"
#define APPLE_MAX 20

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
struct RINGO gAppleCn = { TRUE,4,0,0,-50,18,18,50,1 };



int APPLE::IMAGES_RINGO()
{
	M_INPUT M{};

	M.Input();

	DrawGraph(100, 200, M.gAppleImg[0], TRUE);
	DrawGraph(200, 200, M.gAppleImg[1], TRUE);
	DrawGraph(300, 200, M.gAppleImg[2], TRUE);
	DrawGraph(400, 200, M.gAppleImg[3], TRUE);

	
	/*int red, blue, gold, poison;
	red = DrawCircle(0, 0, 80, 0xff0000, TRUE);
	blue = DrawCircle(100, 100, 80, 0x00ff00, TRUE);
	gold = DrawCircle(200, 200, 80, 0xffd700, TRUE);
	poison = DrawCircle(300, 300, 80, 0xff00ff, TRUE);
	*/

	// AppleControl();
	
	return 0;
}


void APPLE::AppleControl(void)
{
	M_INPUT M{};

	M.Input();
	
	struct RINGO gApple[APPLE_MAX]{};

	// �����S�̏����ݒ�
	for (int i = 0; i < APPLE_MAX; i++) {
		gApple[i].flg = TRUE;
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == TRUE) {

			//DrawString(200, 200, "haitteru", 0xffffff, 0);

			// �����S�̕\��
			DrawGraph(gApple[i].x, gApple[i].y, gApple[i].img, TRUE);

			// �^���������Ɉړ�
			gApple[i].y = gApple[i].speed * 10;

			// Y����1000�ɂȂ��������
			/*if (gApple[i].y > 1000)
				gApple[i].flg = FALSE;*/
		}
	}
	
	CreateApple();
}

int APPLE::CreateApple()
{

	M_INPUT M{};

	M.Input();

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gApple00;
			switch (GetRand(19))
			{
			case 0: 
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:	// �ԃ����S�o��
				gApple[i].type = M.gAppleImg[0];
				break;
			case 12: 
			case 13:
			case 14:
			case 15:
			case 16: // �����S�o��
				gApple[i].type = M.gAppleImg[1];
				break;
			case 17:
			case 18: // �������S�o��
				gApple[i].type = M.gAppleImg[2];
				break;
			case 19: // �Ń����S�o��
				gApple[i].type = M.gAppleImg[3];
				break;
			}
			
			gApple[i].x = GetRand(7) * 120 + 100;
			gApple[i].speed = gApple[i].type * 1;
			
			// ����
			return TRUE;
		}
	}

	// ���s
	return FALSE;
}

void APPLE::AppleSetting()
{
	M_INPUT M{};

	M.Input();

	
}