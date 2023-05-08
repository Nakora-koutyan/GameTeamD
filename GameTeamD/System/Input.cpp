#include<stdio.h>
#include"DxLib.h"
#include"Input.h"

int G_INPUT::Input() {

	if ((gBackScreen = LoadGraph("Material/Images/Title.png")) == -1) return -1;

}