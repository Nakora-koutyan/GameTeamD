#pragma once

#define RANK_MAX 5

/****************************************
* �\����
*****************************************/
//�����L���O�f�[�^�\����
struct RankingData {
	int      no;
	char name[11];
	long score;
};

//r�����L���O�f�[�^�̕ϐ��錾
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

