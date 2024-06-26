#include "Enemy_bullet.h"
#include "../../Utility/InputControl.h"
#include"../../Objects/GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
Enemy_bullet::Enemy_bullet() : direction(0.0f), images(NULL)
{

}

//�f�X�g���N�^
Enemy_bullet::~Enemy_bullet()
{

}

//����������
void Enemy_bullet::Initialize()
{
    //�摜�̓ǂݍ���
    images = LoadGraph("Resource/Images/�e�L�e.png");
    //�����̐ݒ�
    radian = 6.9;
    //�傫���̐ݒ�
    scale = 64.0f;
    //�����摜�̐ݒ�
    image = images;


   /* type = enemy_bullet;*/
    //�����U���񍐂̐ݒ�

}

//�X�V����
void Enemy_bullet::Update()
{
    //�ړ�����
    Movement();
    //�A�j���[�V��������
    /*AnimeControl();*/

}

//�`�揈��
void Enemy_bullet::Draw()const
{

    //�G���e�摜�̕`��
    DrawRotaGraphF(location.x, location.y, 0.4, radian, image, TRUE, 0);


    //�e�N���X�̕`�揈�����Ăяo��
    __super::Draw();
}


//�C��������
void Enemy_bullet::Finalize()
{
    //�g�p�����摜���������
    DeleteGraph(images);
    /*DeleteGraph(animation[1]);*/
}

//�����蔻��ʒm����
void Enemy_bullet::OnHitCollision(GameObject* hit_object)
{
    //�����������̏���

}

//�ړ�����
void Enemy_bullet::Movement()
{

    //������ֈړ���������
    location.y -= radian;




    //�E�̕ǂɓ�����ƍ��̕ǂɍs��
}
//��ʒ[�ɓ��B������A�i�s�����𔽓]����
/// if (((location.x + direction.x) < box_size.x) ||
//    (640.0f - box_size.x) < (location.x + direction.x))
//{
//    direction.x = -1.0f;
//}
//if (((location.y + direction.y) < box_size.y) ||
//    (480.0f - box_size.y) < (location.y + direction.y))
//{
//    direction.y = -1.0f;
//}/
//�i�s�����Ɍ������āA�ʒu����ύX����
///location += direction;
//} /
//���ɂ߁[����񐧌�
//void Bom::AnimeControl()
//{
//    //?��[�ރJ�E���g�����Z����
//    animation_count++;
//
//    //30�t���[���ڂɓ��B������
//    if (animation_count >= 30)
//    {
//        //�J�E���g�̃��Z�b�g
//        animation_count = 0;
//
//        //�摜�̐؂�ւ�
//        if (image == animation[0])
//        {
//            image = animation[1];
//        }
//        else
//        {
//            image = animation[0];
//        }
//    }
//}