#include<stdio.h>
#include<DxLib.h>
#include"../GameTeamD/Title/Title.h"
#include"../GameTeamD/GameMain/GameMain.h"
#include"../GameTeamD/GameMain/Stage.h"
#include"../GameTeamD/GameMain/Player.h"
#include"../GameTeamD/GameMain/Apple.h"
#include"../GameTeamD/GameMain/Result.h"
#include"../GameTeamD/Ranking/DrawRanking.h"
#include"../GameTeamD/Ranking/Ranking.h"
#include"../GameTeamD/Help/Help.h"
#include"../GameTeamD/End/Credit.h"
#include"../GameTeamD/End/End.h"
#include"../GameTeamD/System/FpsController.h"
#include"../GameTeamD/System/PadInput.h"
#include"../GameTeamD/System/Collision.h"
#include"../GameTeamD/System/AbstractScene.h"

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
int gOldKey;           // �O��̓��̓L�[
int gNowKey;           // ����̓��̓L�[
int gKeyFlg;           // ���̓L�[���

int gGameMode = E_TITLE;    // �Q�[�����[�h

int gTitleImg;         // �^�C�g���摜

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

    TITLE title;

	

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && gGameMode != E_CLOSE && !(gKeyFlg & PAD_INPUT_START)) {


		// ��ʂ̏�����
		ClearDrawScreen();

		title.print();

		// ����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;
}