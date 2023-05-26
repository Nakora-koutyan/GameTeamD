#include"Apple.h"

APPLE::APPLE()
{
	flg = FALSE;  // ダミーデータ（使用）

	location.x =  0;  // ダミーデータ（ｘ）
	location.y = 0;   // ダミーデータ（ｙ）
	 erea.width = 63;     // ダミーデータ（ｗ）
	 erea.height = 120;	 // ダミーデータ（ｈ）
	 speed = 50; // ダミーデータ（speed）
	 point = 1;	 // ダミーデータ（point加算）
}

APPLE::~APPLE()
{

}

void APPLE::AppleControl(void)
{
	// リンゴの初期設定
	if (flg == TRUE) 
	{
		// 真っすぐ下に移動
		location.y += speed;

		// Y軸が1000になったら消去
		if (location.y > 1000)
			flg = FALSE;
	}
}

void APPLE::Draw()const 
{
	if (flg == TRUE) {
		// リンゴの表示
		DrawRotaGraph(location.x, location.y, 1, 0, img, TRUE);
	}
}