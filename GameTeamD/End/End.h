#pragma once
<<<<<<< HEAD
class END
=======
#include "DxLib.h"
#include "../System/AbstractScene.h"

class END : public AbstractScene
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
{
public:
	//�ϐ�
	static int E_count;
	static int E_second;

	//�摜�n���h���i�[�p�ϐ�
	static int mImageHandle;

<<<<<<< HEAD
	//�����o�֐�
	void End_Initialize();	//������
	void End_Finalize();	//�I��
	void End_Update();		//�X�V
	void End_Draw();		//�`��
=======
	END();
	//�f�X�g���N�^
	~END() {};
	//SceneManager�p
	//void Update() override;		//�`��ȊO�̍X�V����
	//void Draw()const override;		//�`��̍X�V����
	//AbstractScene* ChangeScene() override;
>>>>>>> parent of 97bad70 (Merge branch 'main' into yoshiki)
};