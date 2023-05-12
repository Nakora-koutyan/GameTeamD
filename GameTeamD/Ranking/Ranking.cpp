#include<stdio.h>
#include"DxLib.h"
#include"Ranking.h"
#include"../System/Input.h"

/****************************************
* �����L���O���
*****************************************/
void Ranking::DrawRanking(void)
{
	M_INPUT M;

	M.Input();

	//�X�Ń��j���[�ɖ߂�
	//if (gKeyFlg & PAD_INPUT_M) gGameMode = TITLE;

	//�����L���O�摜��\��
	DrawGraph(0, 0, M.gRankingImg, FALSE);

	//�����L���O�ꗗ��\��
	SetFontSize(18);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(50, 170 + i * 25, 0xffffff,
			"%2d %-10s %10d",
			gRanking[i].no,
			gRanking[i].name,
			gRanking[i].score);
	}
	DrawString(100, 450, "--- �X�y�[�X�L�[�������ă^�C�g���֖߂� ---", 0xff0000, 0);
}

/****************************************
* �����L���O�f�[�^�̕ۑ�
*****************************************/
int SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/*�G���[����*/
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^���z��f�[�^����������
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name,
			gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
	return 0;
}

/****************************************
* �����L���O�f�[�^�ǂݍ���
*****************************************/
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//�t�@�C���I�[�v��
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//�G���[����
		printf("Ranking Data Error\n");
		return -1;
	}

	//�����L���O�f�[�^���z��f�[�^��ǂݍ���
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return 0;
}