//#include "DxLib.h"
//#include "End.h"
//#include"../System/PadInput.h"
//#include"../System/Input.h"
//
//int g_WaitTime = 0;
//int g_PosY;
//
//void End(void)
//{
//
//	M_INPUT M;
//
//	M.Input();
//
//	DrawGraph(0, 0, M.gRankingImg, FALSE);
//
//	//エンディング表示
//	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;
//
//	SetFontSize(24);
//	DrawString(100, 170 + g_PosY, "タイトル　　　リンゴ落とし", 0xFFFFFF);
//	DrawString(100, 200 + g_PosY, "バージョン　　1.0", 0xFFFFFF);
//	DrawString(100, 230 + g_PosY, "最終更新日　　2023年05月26日", 0xFFFFFF);
//	DrawString(100, 260 + g_PosY, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
//	DrawString(100, 290 + g_PosY, "　　　　　　　☆", 0xFFFFFF);
//	DrawString(100, 320 + g_PosY, "　　　　　　　・", 0xFFFFFF);
//	DrawString(100, 350 + g_PosY, "　　　　　　　・", 0xFFFFFF);
//	DrawString(100, 380 + g_PosY, "　　　　　　　・", 0xFFFFFF);
//	DrawString(100, 410 + g_PosY, "　　　　　　　・", 0xFFFFFF);
//	DrawString(100, 440 + g_PosY, "　　　　　　　・", 0xFFFFFF);
//	DrawString(100, 470 + g_PosY, "素材利用", 0xFFFFFF);
//	DrawString(100, 500 + g_PosY, "　BGM　　　 　ＸＸＸＸ", 0xFFFFFF);
//	DrawString(100, 530 + g_PosY, "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0xFFFFFF);
//
//	//タイムの加算処理＆終了
//	//if (++g_WaitTime > 1000) GameMode = 99;
//}