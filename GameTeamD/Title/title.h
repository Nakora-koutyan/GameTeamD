#pragma once
#include"../System/PadInput.h"
#include"../System/AbstractScene.h"
class TITLE : public AbstractScene
{
private:
	enum mode {
		E_TITLE,
		E_MAIN,
		E_RANKING,
		E_HELP,
		E_INPUTNAME,
		E_RESULT,
		E_END,
		E_CLOSE
	};
	int g_MenuNumber = 0;
	int gGameMode = E_TITLE;
	int vol = 255;
	int gBackScreen = LoadGraph("Material/Images/Title.png");
	int gTitleBGM = LoadSoundMem("Material/Sounds/BGM/Title.wav");
	int gCursor_Move = LoadSoundMem("Material/Sounds/SE/cursor1.wav");
	int gCursor_Enter = LoadSoundMem("Material/Sounds/SE/eats.wav");
public:

	TITLE();

	// �f�X�g���N�^
	virtual ~TITLE();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};
