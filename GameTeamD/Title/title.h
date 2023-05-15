#pragma once
#include"../System/PadInput.h"
class TITLE : public InputControl
{
private:
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
	int g_MenuNumber = 0;
public:

	void print();
};

