#include "PadInput.h"

XINPUT_STATE input;
int InputControl::key_flg;
int InputControl::now_key;
int InputControl::old_key;

void InputControl::Update()
{
	old_key = now_key;
	now_key = GetJoypadXInputState(DX_INPUT_PAD1,&input);
	key_flg = now_key & ~old_key; //’·‰Ÿ‚µ‹‘”Û(2ƒtƒŒ[ƒ€ˆÈã“Ç‚Ì‹‘”Û)
}

int InputControl::GetKey(int key) //’·‰Ÿ‚µ‹–—e
{
	if (now_key & key)
	{
		return TRUE;
	}

	return FALSE;
}

int InputControl::GetKeyDown(int key) //’·‰Ÿ‚µ‹‘”Û
{
	if (key_flg & key)
	{
		return TRUE;
	}

	return FALSE;
}
