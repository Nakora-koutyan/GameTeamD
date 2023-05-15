#pragma once

class TITLE
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
public:
	int t = 0;

	int g_KeyFlg;
	int g_MenuNumber;

	void print();
};

