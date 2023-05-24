#include"Apple.h"
#include"../System/Input.h"
#define APPLE_MAX 20

struct RINGO {
	int flg;        // 使用フラグ
	int type;       // タイプ
	int img;         // 画像
	int x, y, w, h;  // 座標、幅、高さ
	int speed;       // 移動速度
	int point;       // スコア加算ポイント

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


void APPLE::AppleControl(void)
{
	//this;

	M_INPUT M{};

	M.Input();
	
	// リンゴの初期設定
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == TRUE) {

			//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);

			// リンゴの表示
			DrawGraph(gApple[i].x, gApple[i].y, gApple[i].img, TRUE);

			// 真っすぐ下に移動
			gApple[i].y += gApple[i].speed;

			// Y軸が1000になったら消去
			if (gApple[i].y > 1000)
				gApple[i].flg = FALSE;
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
			gApple[i].type = GetRand(19);
			gApple[i].img = M.gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 120 + 100;

			switch (gApple[i].type)
	        {
	        case 0:
		           // 赤リンゴ出現
		           gApple[i].speed = 1;
		     break;

			case 1:
					// 青リンゴ出現
					gApple[i].speed = 3;
			break;

			case 3:
					// 金リンゴ出現
					gApple[i].speed = 5;
			break;

			case 4:
					// 毒リンゴ出現
					gApple[i].speed = 0.5;
			break;
	        }

			
			// 成功
		return TRUE;
		}
	}
			
	// 失敗
	return FALSE;
}

//for (int i = 0; i < APPLE_MAX; i++) {
	//	if (gApple[i].flg == FALSE) {
	//		gApple[i] = gApple00;
	//		switch (GetRand(19))
	//		{
	//		case 0: 
	//		case 1:
	//		case 2:
	//		case 3:
	//		case 4:
	//		case 5:
	//		case 6:
	//		case 7:
	//		case 8:
	//		case 9:
	//		case 10:
	//		case 11:	// 赤リンゴ出現
	//			gApple[i].type = M.gAppleImg[0];
	//			break;
	//		case 12: 
	//		case 13:
	//		case 14:
	//		case 15:
	//		case 16: // 青リンゴ出現
	//			gApple[i].type = M.gAppleImg[1];
	//			break;
	//		case 17:
	//		case 18: // 金リンゴ出現
	//			gApple[i].type = M.gAppleImg[2];
	//			break;
	//		case 19: // 毒リンゴ出現
	//			gApple[i].type = M.gAppleImg[3];
	//			break;
	//		}
	//		
	//		gApple[i].x = GetRand(7) * 120 + 100;
	//		gApple[i].speed = gApple[i].type * 1;



//switch (gApple[i].type)
			//{
			//case 0: 
			//case 1:
			//case 2:
			//case 3:
			//case 4:
			//case 5:
			//case 6:
			//case 7:
			//case 8:
			//case 9:
			//case 10:
			//case 11:	// 赤リンゴ出現
			//      gApple[i].speed = 1;
			//break;
			//case 12: 
			//case 13:
			//case 14:
			//case 15:
			//case 16: // 青リンゴ出現
			//      gApple[i].speed = 2;
			//break;
			//case 17:
			//case 18: // 金リンゴ出現
			//	gApple[i].speed = 3.5;
			//	break;
			//case 19: // 毒リンゴ出現
			//	gApple[i].speed = 0.5;
			//	break;
			//}