#pragma once

#define RANK_MAX 5

/****************************************
* �\����
*****************************************/
//�����L���O�f�[�^�\����
struct RankingData {
	int no;
	char name[11];
	long score;
};

//r�����L���O�f�[�^�̕ϐ��錾
struct RankingData  gRanking[RANK_MAX];

class Ranking
{
public:

	int ReadRanking();
	int SaveRanking();

	void DrawRanking();
	void SortRanking();
    void InputRanking();
};

