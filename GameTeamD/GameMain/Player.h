#pragma once
class C_PLAYER
{
public:

	int gOldKey;           // �O��̓��̓L�[
	int gNowKey;           // ����̓��̓L�[
	int gKeyFlg;           // ���̓L�[���


	struct PLAYER {
		int flg;          // �g�p�t���O
		int x, y;         // ���W
		int w, h;         // ���E����
		int count;        // �^�C�~���O�p
		int speed;        // �ړ�
	};

	// ���@�̕ϐ��錾
	struct PLAYER gPlayer;

    gPlayer.x = 640;


	void input();
};