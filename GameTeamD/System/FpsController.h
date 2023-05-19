#pragma once

class FpsController {
private:
    int frame_time; //1�t���[���̎���(�~���b)
    int wait_time; //�҂�����
    int last_time, now_time; //�Ō�Ɏ擾�������ԂƁC���̎���
    float count; //�t���[���̃J�E���g
    float fps; //�\�����邵��FPS�l
    int update_time; //�\���l���X�V���鎞��
    int last_update; //�Ō�ɕ\���l���X�V��������
    //������
    void Init(float RefreshRate, int UpdateTime);
public:

    //60frame�o�Ă��邩�m�F���邽�߂̕��ώ��Ԏ��n
    //�����t���R���X�g���N�^
    FpsController(float RefreshRate, int UpdateTime) {
        //����
        Init(RefreshRate, UpdateTime);
    }
    //�����Ȃ��̏ꍇ�Ă΂��f�t�H���g�l
    FpsController() {
        Init(60.0f, 800);
    }

    //�҂����Ԃ̌v�Z
    void Wait();

    //FPS�l�̌v�Z
    float Get();

    //�`�揈��
    void Disp() {
        SetFontSize(10);
        DrawFormatString(10, 10, 0xffffff, "fps:%0.1f", fps);
    }
    //�������܂Ƃ߂�����
    float All() {
        Get();
        Wait();
        return (fps);
    }

};

