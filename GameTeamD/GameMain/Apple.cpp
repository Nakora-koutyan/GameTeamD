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
	flg = FALSE;  // ダミーデータ（使用）

	location.x =  0;  // ダミーデータ（ｘ）
	location.y = 0;   // ダミーデータ（ｙ）
	 erea.width = 63;     // ダミーデータ（ｗ）
	 erea.height = 120;	 // ダミーデータ（ｈ）
	 speed = 50; // ダミーデータ（speed）
	 point = 1;	 // ダミーデータ（point加算）

	//// リンゴの初期設定
	//for (int i = 0; i < APPLE_MAX; i++) {
	//	if (gApple[i].flg == TRUE) {

	//		//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);

	//		// リンゴの表示
	//		DrawGraph(gApple[i].x, gApple[i].y, gApple[i].img, TRUE);

	//		// 真っすぐ下に移動
	//		gApple[i].y += gApple[i].speed;

	//		// Y軸が1000になったら消去
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


	// リンゴの初期設定

	if (flg == TRUE) {

		//DrawString(gApple[i].x, gApple[i].y, "haitteru", 0xffffff, 0);



		// 真っすぐ下に移動
		location.y += speed;

		// Y軸が1000になったら消去
		if (location.y > 1000)
			flg = FALSE;

	}
}

void APPLE::Draw()const {
	if (flg == TRUE) {
		// リンゴの表示
		DrawRotaGraph(location.x, location.y, 1, 0, img, TRUE);
	}
}

