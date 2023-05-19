#include <stdio.h>
#include"DxLib.h"
#include"Ranking.h"
#include"../System/Input.h"

/****************************************
* 構造体
*****************************************/
//ランキングデータ構造体
struct RankingData {
	int no;
	char name[11];
	long score;
};

//rランキングデータの変数宣言
struct RankingData  gRanking[RANK_MAX];

/****************************************
* ランキング画面
*****************************************/
void Ranking::DrawRanking(void)
{
	M_INPUT M;

	M.Input();

	//でメニューに戻る
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
int Ranking::SaveRanking(void)
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
		fprintf(fp,"%2d %10s %10d\n", gRanking[i].no, gRanking[i].name,
			gRanking[i].score);
	}

	//ファイルクローズ
	fclose(fp);
	return 0;
}

/****************************************
* ランキング入力処理
*****************************************/
void Ranking::InputRanking(void)
{
	M_INPUT M;

	M.Input();

	//ランキング画像表示
	DrawGraph(0, 0, M.gRankingImg, FALSE);

	//フォントサイズの設定
	SetFontSize(16);

	//名前入力指示文字列の描画
	DrawString(80, 150, "ランキングに登録します。", 0xFFFFFF);
	DrawString(80, 170, "名前を英字で入力して下さい。", 0xFFFFFF);

	//名前の入力
	DrawString(80, 200, "> ", 0xFFFFFF);
	DrawBox(90, 195, 200, 220, 0xFFFF00, TRUE);
	if (KeyInputSingleCharString(90, 200, 10, gRanking[RANK_MAX - 1].name, FALSE) == 1) {
		gRanking[RANK_MAX - 1].score = M.gScore;             //ランキングデータの10番目にスコアを表示
		//SortRanking();                                     //ランキングの並び替え
		//SaveRanking();                                     //ランキングデータ並び替え
		/*gGameMode = E_RANKING;*/                               //ゲームモードの変更
	}
}

/****************************************
* ランキング並び替え
*****************************************/
void Ranking::SortRanking(void)
{

	int i, j;
	RankingData work;

	//選択法ソート
	for (i = 0; i < RANK_MAX; i++) {
		for (j = i + 1; j < RANK_MAX - 1; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}
	//順位付け
	for (i = 0; i < RANK_MAX; i++) {
		gRanking[i].no = 1;
	}
	//得点が同じ場合は、同じ順位とする
	//同順位があった場合の次の順位はデータ戸数が加算された順位とする
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}

/****************************************
* ランキングデータ読み込み
*****************************************/
int Ranking::ReadRanking(void)
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