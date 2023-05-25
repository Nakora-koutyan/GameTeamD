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
	
	int LoadRanking();   //�����L���O�摜�̓Ǎ�
	int ReadRanking();   //�����L���O�f�[�^�̓Ǎ�
	int SaveRanking();   //�����L���O�f�[�^�̕ۑ�

	void DrawRanking();  //�����L���O�`�揈��
	void SortRanking();  //�����L���O�f�[�^�̕��ёւ�
    void InputRanking(); //�����L���O������
};

