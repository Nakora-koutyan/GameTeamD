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
	int gBackScreen;
	int gTitleBGM;
	int gCursor_Move;
	int gCursor_Enter;
	int gCursor;
public:

	TITLE();

	// �f�X�g���N�^
	~TITLE();

	// �`��ȊO�̍X�V����������
	virtual AbstractScene* Update() override;

	// �`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;
};
