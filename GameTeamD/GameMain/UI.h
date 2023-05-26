#pragma once
#include"DxLib.h"

class UI
{
private:
	float x, y;

	int width;
	int height;

	int score;
	int time;
	int acqu[4];
public:
	UI();

	void Update();
	void Draw() const;

	void SetTime(int time) { this->time = time; }
	void AddScore(int score) { this->score += score; }
	void AddAcqu(int acqu[4]) {
		for (int i = 0; i < 3; i++)
		{
			this->acqu[i] = acqu[i];
		}
	}
};

