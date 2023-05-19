#include <stdio.h>
#include"DxLib.h"
#include"Ranking.h"
#include"../System/Input.h"

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

/****************************************
* �����L���O���
*****************************************/
void Ranking::DrawRanking(void)
{
	M_INPUT M;

	M.Input();

	//�Ń��j���[�ɖ߂�
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
int Ranking::SaveRanking(void)
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
		fprintf(fp,"%2d %10s %10d\n", gRanking[i].no, gRanking[i].name,
			gRanking[i].score);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
	return 0;
}

/****************************************
* �����L���O���͏���
*****************************************/
void Ranking::InputRanking(void)
{
	M_INPUT M;

	M.Input();

	//�����L���O�摜�\��
	DrawGraph(0, 0, M.gRankingImg, FALSE);

	//�t�H���g�T�C�Y�̐ݒ�
	SetFontSize(16);

	//���O���͎w��������̕`��
	DrawString(80, 150, "�����L���O�ɓo�^���܂��B", 0xFFFFFF);
	DrawString(80, 170, "���O���p���œ��͂��ĉ������B", 0xFFFFFF);

	//���O�̓���
	DrawString(80, 200, "> ", 0xFFFFFF);
	DrawBox(90, 195, 200, 220, 0xFFFF00, TRUE);
	if (KeyInputSingleCharString(90, 200, 10, gRanking[RANK_MAX - 1].name, FALSE) == 1) {
		gRanking[RANK_MAX - 1].score = M.gScore;             //�����L���O�f�[�^��10�ԖڂɃX�R�A��\��
		//SortRanking();                                     //�����L���O�̕��ёւ�
		//SaveRanking();                                     //�����L���O�f�[�^���ёւ�
		/*gGameMode = E_RANKING;*/                               //�Q�[�����[�h�̕ύX
	}
}

/****************************************
* �����L���O���ёւ�
*****************************************/
void Ranking::SortRanking(void)
{

	int i, j;
	RankingData work;

	//�I��@�\�[�g
	for (i = 0; i < RANK_MAX; i++) {
		for (j = i + 1; j < RANK_MAX - 1; j++) {
			if (gRanking[i].score <= gRanking[j].score) {
				work = gRanking[i];
				gRanking[i] = gRanking[j];
				gRanking[j] = work;
			}
		}
	}
	//���ʕt��
	for (i = 0; i < RANK_MAX; i++) {
		gRanking[i].no = 1;
	}
	//���_�������ꍇ�́A�������ʂƂ���
	//�����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�ː������Z���ꂽ���ʂƂ���
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (gRanking[i].score > gRanking[j].score) {
				gRanking[j].no++;
			}
		}
	}
}

/****************************************
* �����L���O�f�[�^�ǂݍ���
*****************************************/
int Ranking::ReadRanking(void)
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