#pragma once

#define RANK_MAX 5

/****************************************
* 構造体
*****************************************/
//ランキングデータ構造体
struct RankingData {
	int      no;
	char name[11];
	long score;
};

//rランキングデータの変数宣言
struct RankingData  gRanking[RANK_MAX];

class Ranking
{
public:
	
	/*const int RANK_MAX = 5;*/

	int ReadRanking();
	int SaveRanking();
	int gScore;

	void DrawRanking();
	void SortRanking();
    void InputRanking();
};

