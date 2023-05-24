#include<stdio.h>
#include"DxLib.h"
#include"Title/Title.h"
#include"GameMain/GameMain.h"
#include"GameMain/Stage.h"
#include"GameMain/Player.h"
#include"GameMain/Apple.h"
#include"GameMain/Result.h"
#include"Ranking/Ranking.h"
#include"Help/Help.h"
#include"End/Credit.h"
#include"End/End.h"
#include"System/FpsController.h"
#include"System/PadInput.h"
#include"System/Collision.h"
#include"System/AbstractScene.h"
#include"System/Input.h"
#include"System/wh.h"


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
*�@�ϐ��̐錾(�O���[�o���ϐ�)
***************************************/
//int gGameMode = E_TITLE;    // �Q�[�����[�h

int gTitlebgm;         // 

int gScore = 0;        // �X�R�A



/**************************************
*�@�v���O�����̊J�n
***************************************/
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// FPS�̌v���ƕ\�����s�����[�J���ϐ��̐錾
	LONGLONG nowTime = GetNowHiPerformanceCount();
	LONGLONG oldTime = nowTime;
	LONGLONG fpsCheckTime;
	double deltaTime = 0;
	int fpsCounter = 0;
	int fps = 0;

	// �^�C�g����ݒ�
	SetMainWindowText("pick up apples");

	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y�ݒ�	
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT,32);

	// DX���C�u�����̏���������
	if (DxLib_Init() == -1)return -1;

	// �`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	//SetLoopSamplePosSoundMem(371945, gMainbgm); 
	SetLoopSamplePosSoundMem(109696, gTitlebgm); 

	M_INPUT M{};

	/*PLAYER Box;*/

	APPLE apple{};

	GAMEMAIN stage;

	TITLE T;
	
	M.Input();

	//���[�v�O��FPS�v����������
	fpsCheckTime = GetNowHiPerformanceCount();
	fps = 0;
	fpsCounter = 0;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 ) {


		// ��ʂ̏�����
		ClearDrawScreen();

		InputControl::Update();

		DrawGraph(0, 0, M.gBackScreen, 0);

		DrawString(20, 20, "debug...", GetColor(255, 255, 255));

		// �����S�\���m�F�p
		//apple.IMAGES_RINGO();
		apple.AppleControl();

		//title.print();

		T.print();

		//1���[�v���_�̃V�X�e�����Ԃ��擾
		oldTime = nowTime;
		nowTime = GetNowHiPerformanceCount();

		//1���[�v�̎��Ԍo�߂����߂�
		deltaTime = (nowTime - oldTime) / 1000000.0f;

		//1�b�Ԃ�FPS���v������A1�b���Ƃɏ���������
		fpsCounter++;
		if (nowTime - fpsCheckTime > 1000000) {
			fps = fpsCounter;
			fpsCounter = 0;
			fpsCheckTime = nowTime;
		}

		//�v���C���[�摜�\���֐��̐錾
		//Box.IMAGES_PLAYER();

		//FPS�̕\��
		SetFontSize(16);
		DrawFormatString(390, 5, 0xffffff, "FPS:%3d DELTA: %8.6fsec", fps, deltaTime);

		 //����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	//delete player;

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;
}