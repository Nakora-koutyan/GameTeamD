#include<stdio.h>
#include"DxLib.h"
#include"Title/Title.h"
#include"GameMain/GameMain.h"
#include"GameMain/Player.h"
#include"GameMain/Apple.h"
#include"GameMain/Result.h"
#include"System/FpsController.h"
#include"System/PadInput.h"
#include"System/AbstractScene.h"
#include"System/Input.h"
#include"System/SceneManager.h"


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
//const int SCREEN_WIDTH = 1280;
//const int SCREEN_HEIGHT = 720;


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

	PLAYER Box;

	APPLE apple{};

	TITLE T;
	
	M.Input();
	// �Q�[�����[�v
	while (ProcessMessage() == 0 ) {


		// ��ʂ̏�����
		ClearDrawScreen();

		InputControl::Update();

		DrawGraph(0, 0, M.gBackScreen, 0);

		DrawString(20, 20, "debug...", GetColor(255, 255, 255));

		// �����S�\���m�F�p
		//apple.IMAGES_RINGO();

		//T.print();
		SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TITLE()));

		printf("�����l����͂��Ă���������");
		while (sceneMng.Update() != nullptr) {
			sceneMng.Draw();
		}

		//�v���C���[�摜�\���֐��̐錾
		//Box.IMAGES_PLAYER();

		 //����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	//delete player;

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;
}