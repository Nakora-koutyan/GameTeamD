#include<stdio.h>
#include"DxLib.h"
#include"Title/Title.h"
#include"GameMain/GameMain.h"
#include"GameMain/Stage.h"
#include"GameMain/Player.h"
#include"GameMain/Apple.h"
#include"GameMain/Result.h"
#include"Ranking/DrawRanking.h"
#include"Ranking/Ranking.h"
#include"Help/Help.h"
#include"End/Credit.h"
#include"End/End.h"
#include"System/FpsController.h"
#include"System/PadInput.h"
#include"System/Collision.h"
#include"System/AbstractScene.h"
#include"System/Input.h"


/**************************************
*�@�񋓌^�̐錾
***************************************/
enum mode {
	E_TITLE,
	E_INIT,
	E_MAIN,
	E_RANKING,
	E_HELP,
	E_INPUTNAME,
	E_RESULT,
	E_END,
	E_CLOSE
};
/**************************************
*�@�ϐ��̐錾
***************************************/
// ��ʗ̈�̑傫��
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// �����S�̍ő吔
const int APPLE_MAX = 20;

/**************************************
*�@�ϐ��̐錾(�O���[�o���ϐ�)
***************************************/
int gGameMode = E_TITLE;    // �Q�[�����[�h

int gTitlebgm;         // 

int gScore = 0;        // �X�R�A

int gItemImg[4];       // �A�C�e���摜

/**************************************
*�@�v���O�����̊J�n
***************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �^�C�g����ݒ�
	SetMainWindowText("pick up apples");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y�ݒ�
	SetWindowSize(1280, 720);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//SetLoopSamplePosSoundMem(371945, gMainbgm); //
	SetLoopSamplePosSoundMem(109696, gTitlebgm); //

    M_INPUT M;

	//C_PLAYER* player = new C_PLAYER;
	
	M.Input();
	// �Q�[�����[�v
	while (ProcessMessage() == 0 && gGameMode != E_CLOSE) {


		// ��ʂ̏�����
		ClearDrawScreen();

		DrawGraph(0, 0, M.gBackScreen, 0);

		DrawString(20, 20, "debug...", GetColor(255, 255, 255));

		//title.print();

		//player->Draw();

		// ����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	//delete player;

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;
}