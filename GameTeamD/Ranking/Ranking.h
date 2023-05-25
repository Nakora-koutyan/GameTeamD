#pragma once

#define RANK_MAX 5

class Ranking
{
private:
	enum mode {
		E_TITLE,
		E_RANKING,
		E_INPUTNAME,
	};

public:
	int gScore;
	int gRankingImg;
	int gGameMode = E_RANKING;
	
	int LoadRanking();   //ランキング画像の読込
	int ReadRanking();   //ランキングデータの読込
	int SaveRanking();   //ランキングデータの保存

	void DrawRanking();  //ランキング描画処理
	void SortRanking();  //ランキングデータの並び替え
    void InputRanking(); //ランキングン入力
};

