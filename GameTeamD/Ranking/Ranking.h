#pragma once

#define RANK_MAX 5

class Ranking
{
public:

	
	int gScore;
	
	int ReadRanking();   //�����L���O�f�[�^�̓Ǎ�
	int SaveRanking();   //�����L���O�f�[�^�̕ۑ�

	void DrawRanking();  //�����L���O�`�揈��
	void SortRanking();  //�����L���O�f�[�^�̕��ёւ�
    void InputRanking(); //�����L���O������
};

