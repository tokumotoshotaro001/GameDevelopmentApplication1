//#include "Enemy.h"
//#include "DxLib.h"
//
//Enemy::Enemy() :animation_count(0), direction(0.0f)
//{
//	animation[0] = NULL;
//	animation[1] = NULL;
//}
//
//Enemy::~Enemy()
//{
//
//}
//
////����������
//void Enemy::Initialize()
//{
//	//�摜�̓ǂݍ���
//	animation[0] = LoadGraph("Resource/Images/�n�R�e�L1.png");
//	animation[1] = LoadGraph("Resource/Images/�n�R�e�L2.png");
//
//	//�G���[�`�F�b�N
//	if (animation[0] == -1 || animation[1] == -1)
//	{
//		throw()
//	}
//}

#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^
Enemy::Enemy() : animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/�n�R�e�L1.png");
	animation[1] = LoadGraph("Resource/Images/�n�R�e�L2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	scale = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];
}

//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Enemy::Draw() const
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, filp_flag);

	//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);
	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}

//�ړ�����
void Enemy::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//���E�̑���
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		velocity.x += -1.0f;
		filp_flag = TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		velocity.x += 1.0f;
		filp_flag = FALSE;
	}
	else
	{
		velocity.x += 0.0f;
	}
	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Enemy::AnimationControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}