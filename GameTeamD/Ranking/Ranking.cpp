#include<stdio.h>
#include"DxLib.h"
#include"Ranking.h"
#include"../System/Input.h"

/****************************************
* ランキング画面
*****************************************/
void Ranking::DrawRanking(void)
{
	M_INPUT M;

	M.Input();

	//スでメニューに戻る
	//if (gKeyFlg & PAD_INPUT_M) gGameMode = TITLE;

	//ランキング画像を表示
	DrawGraph(0, 0, M.gRankingImg, FALSE);

	//ランキング一覧を表示
	SetFontSize(18);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff,
			"%2d %-10s %10d",
			gRanking[i].no,
			gRanking[i].name,
			gRanking[i].score);
	}
	DrawString(100, 450, "--- スペースキーを押してタイトルへ戻る ---", 0xff0000, 0);
}

/****************************************
* ランキングデータの保存
*****************************************/
int SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/*エラー処理*/
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name,
			gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
	return 0;
}

/****************************************
* ランキングデータ読み込み
*****************************************/
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ分配列データを読み込む
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}