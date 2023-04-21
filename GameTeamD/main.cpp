#include<stdio.h>
#include<DxLib.h>

/**************************************
*�@�񋓌^�̐錾
***************************************/
enum mode {
	TITLE,
	INIT,
	MAIN,
	RANKING,
	HELP,
	INPUTNAME,
	RESULT,
	END,
	CLOSE
};
/**************************************
*�@�ϐ��̐錾
***************************************/
// ��ʗ̈�̑傫��
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// ���@�̏����l�̒萔
const int PLAYER_POS_X = SCREEN_WIDTH / 2;
const int PLAYER_POS_Y = SCREEN_HEIGHT - 100;
const int PLAYER_WIDTH = 20;//63
const int PLAYER_HEIGHT = 60;//120
const int PLAYER_SPEED = 5;
const int PLAYER_HP = 1000;
const int PLAYER_FUEL = 20000;
const int PLAYER_BARRIER = 3;
const int PLAYER_BARRIERUP = 10;

// �G�@�̍ő吔
const int ENEMY_MAX = 8;

// �A�C�e���̍ő�l
const int ITEM_MAX = 3;

/**************************************
*�@�ϐ��̐錾(�O���[�o���ϐ�)
***************************************/
int gOldKey;           // �O��̓��̓L�[
int gNowKey;           // ����̓��̓L�[
int gKeyFlg;           // ���̓L�[���

int gGameMode = TITLE;    // �Q�[�����[�h

int gTitleImg;         // �^�C�g���摜
int gTitlebgm;
int gMenuImg;          // ���j���[�摜
int gConeImg;          // ���j���[�J�[�\���摜

int gScore = 0;        // �X�R�A
int gRankingImg;       // �����L���O��ʔw�i

int gItemImg[2];       // �A�C�e���摜

int gWaitTime = 0;      // �҂�����
int gEndImg;            // �G���h�摜

int gMileage;          // ���s����
int gEnemyCount[4];    // �G�J�E���g
int gEnemyImg[4];      // �G�L�����摜

int gStageImg;         // �X�e�[�W�摜(���H)

int gCarImg;           // �Ԃ̉摜
int gBarrierImg;       // �o���A�̉摜

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

	gTitleImg = LoadGraph("images/Title.png");

	gTitlebgm = LoadSoundMem("Sounds/Title.wav");
	int gMainbgm = LoadSoundMem("Sounds/Main.wav");

	SetLoopSamplePosSoundMem(371945, gMainbgm);
	SetLoopSamplePosSoundMem(109696, gTitlebgm);
	PlaySoundMem(gMainbgm, DX_PLAYTYPE_LOOP);

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && gGameMode != CLOSE && !(gKeyFlg & PAD_INPUT_START)) {


		// ��ʂ̏�����
		ClearDrawScreen();

		DrawGraph(0, 0, gTitleImg, 0);

		// ����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �v���O�����̏I��
	return 0;
}