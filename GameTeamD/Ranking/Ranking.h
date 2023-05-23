#pragma once

#define RANK_MAX 5

class Ranking
{
public:

	
	int gScore;
	
	int ReadRanking();   //ランキングデータの読込
	int SaveRanking();   //ランキングデータの保存

	void DrawRanking();  //ランキング描画処理
	void SortRanking();  //ランキングデータの並び替え
    void InputRanking(); //ランキングン入力
};

