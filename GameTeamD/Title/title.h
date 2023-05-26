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

	// デストラクタ
	~TITLE();

	// 描画以外の更新を実装する
	virtual AbstractScene* Update() override;

	// 描画に関することを実装する
	virtual void Draw() const override;
};
