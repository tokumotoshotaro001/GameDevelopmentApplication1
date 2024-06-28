#include "Bullet.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^
Bullet::Bullet () : direction(0.0f), images(NULL), se(), hit()
{

}

//�f�X�g���N�^
Bullet::~Bullet()
{

}

//����������
void Bullet::Initialize()
{
    se = LoadSoundMem("Resource/Sounds/teki_gahee.wav");
    //�摜�̓ǂݍ���
    images = LoadGraph("Resource/Images/���e.png");
    //�傫���̐ݒ�
    box_size = 35.0f;
    //�����摜�̐ݒ�
    image = images;

    //�����i�s�����̐ݒ�
    if (InputControl::GetKey(KEY_INPUT_LEFT))
    {
        radian = 2.0;
        direction = Vector2D(-1.5f, 1.0f);
    }
    else if (InputControl::GetKey(KEY_INPUT_RIGHT))
    {
        radian = 1.0;
        direction = Vector2D(1.5f, 1.0f);
    }
    else
    {
        radian = DX_PI_F / 2;
        direction = Vector2D(0.0f, 1.0f);
    }

}

//�X�V����
void Bullet::Update()
{
    //�ړ�����
    Movement();
    //�A�j���[�V��������
    //AnimeControl();
}

//�`�揈��
void Bullet::Draw()const
{

    //���e�摜�̕`��
    DrawRotaGraphF(location.x, location.y, 0.3, radian, image, TRUE, 0);

    //�f�o�b�O�p
#if _DEBUG
    //�����蔻��̉���
    Vector2D box_collision_upper_left = location - (box_size / 2.0f);
    Vector2D box_collision_lower_right = location + (box_size / 2.0f);

    DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y,
        box_collision_lower_right.x, box_collision_lower_right.y,
        GetColor(255, 0, 0), FALSE);

#endif
}


//�C��������
void Bullet::Finalize()
{
    //�g�p�����摜���������
    DeleteGraph(images);
    /*DeleteGraph(animation[1]);*/
}


//�����蔻��ʒm����
void Bullet::OnHitCollision(GameObject* hit_object)
{
    //�����������̏���
    hit = true;
}

//bool Bullet::DeleteObject()
//{
//    bool ret = false;
//
//    if (location.x > 640.0f + box_size.x  location.x < 0.0f - box_size.x  hit == true)
//    {
//        ret = true;
//    }
//
//    return ret;
//}

//�ړ�����
void Bullet::Movement()
{
    //���ֈړ���������
    location += direction;

}
