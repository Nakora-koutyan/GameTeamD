//#include "DxLib.h"
//#include "End.h"
//#include"../System/PadInput.h"
//#include"../System/Input.h"
//
//int g_WaitTime = 0;
//int g_PosY;
//
//void End(void)
//{
//
//	M_INPUT M;
//
//	M.Input();
//
//	DrawGraph(0, 0, M.gRankingImg, FALSE);
//
//	//�G���f�B���O�\��
//	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;
//
//	SetFontSize(24);
//	DrawString(100, 170 + g_PosY, "�^�C�g���@�@�@�����S���Ƃ�", 0xFFFFFF);
//	DrawString(100, 200 + g_PosY, "�o�[�W�����@�@1.0", 0xFFFFFF);
//	DrawString(100, 230 + g_PosY, "�ŏI�X�V���@�@2023�N05��26��", 0xFFFFFF);
//	DrawString(100, 260 + g_PosY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
//	DrawString(100, 290 + g_PosY, "�@�@�@�@�@�@�@��", 0xFFFFFF);
//	DrawString(100, 320 + g_PosY, "�@�@�@�@�@�@�@�E", 0xFFFFFF);
//	DrawString(100, 350 + g_PosY, "�@�@�@�@�@�@�@�E", 0xFFFFFF);
//	DrawString(100, 380 + g_PosY, "�@�@�@�@�@�@�@�E", 0xFFFFFF);
//	DrawString(100, 410 + g_PosY, "�@�@�@�@�@�@�@�E", 0xFFFFFF);
//	DrawString(100, 440 + g_PosY, "�@�@�@�@�@�@�@�E", 0xFFFFFF);
//	DrawString(100, 470 + g_PosY, "�f�ޗ��p", 0xFFFFFF);
//	DrawString(100, 500 + g_PosY, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
//	DrawString(100, 530 + g_PosY, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);
//
//	//�^�C���̉��Z�������I��
//	//if (++g_WaitTime > 1000) GameMode = 99;
//}