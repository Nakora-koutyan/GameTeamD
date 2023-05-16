#include"Apple.h"
#include"../System/Input.h"
#define APPLE_MAX 20

struct RINGO {
	int flg;         // 使用フラグ
	int type;        // タイプ
	int img;         // 画像
	int x, y, w, h;  // 座標、幅、高さ
	int speed;       // 移動速度
	int point;       // スコア加算ポイント

};

struct RINGO gEnemy[APPLE_MAX];
struct RINGO lApple[APPLE_MAX];
struct RINGO lApple00 = { TRUE,0,0,0,-50,63,120,0,1 };
struct RINGO lAppleCn = { TRUE,4,0,0,-50,18,18,0,1 };



int APPLE::IMAGES_RINGO()
{
	M_INPUT M;

	M.Input();

	DrawGraph(100, 200, M.gApple[0], TRUE);
	DrawGraph(200, 200, M.gApple[1], TRUE);
	DrawGraph(300, 200, M.gApple[2], TRUE);
	DrawGraph(400, 200, M.gApple[3], TRUE);

	AppleControl();
	
	return 0;
}


void APPLE::AppleControl()
{

	// リンゴの初期設定
	for (int i = 0; i < APPLE_MAX; i++) {
		lApple[i].flg = FALSE;
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		if (lApple[i].flg == TRUE) {

			// リンゴの表示
			DrawRotaGraph(lApple[i].x, lApple[i].y, 1.0f, 0, lApple[i].img, TRUE, FALSE);

			// 真っすぐ下に移動
			lApple[i].y += lApple[i].speed;

			// Y軸が1000になったら消去
			if (lApple[i].y > 1000)
				lApple[i].flg = FALSE;
		}
	}
	CreateApple();
}

int APPLE::CreateApple()
{

	M_INPUT M;

	M.Input();

	for (int i = 0; i < APPLE_MAX; i++) {
		if (lApple[i].flg == FALSE) {
			lApple[i] = lApple00;
			lApple[i].type = GetRand(2);
			lApple[i].img = M.gApple[lApple[i].type];
			lApple[i].x = GetRand(4) * 105 + 40;
			lApple[i].speed = lApple[i].type * 2;
			// 成功
			return TRUE;
		}
	}

	// 失敗
	return FALSE;
}