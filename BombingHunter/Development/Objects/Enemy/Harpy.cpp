#include "Harpy.h"
#include "DxLib.h"

//�R���X�g���N�^
Harpy::Harpy() : animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Harpy::~Harpy()
{

}

//����������
void Harpy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/�n�[�s�[1.png");
	animation[1] = LoadGraph("Resource/Images/�n�[�s�[2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�[�s�[�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];

	//�����i�s�����̕`��
	direction = Vector2D(1.0f, -0.5f);
}

//�X�V����
void Harpy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Harpy::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	__super::Draw();
}

//�I��������
void Harpy::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Harpy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
	DeleteObject;
}

//�ړ�����
void Harpy::Movement()
{
	location.x += 1.0;
	//��ʒ[�ɓ��B������A�i�s�����𔽓]����
	//if (((location.x + direction.x) < box_size.x) || (640.0f - box_size.x) < (location.x + direction.x))
	//{
	//	direction.x *= -1.0f;
	//}
	///*if (((location.y + direction.y) < box_size.y) || (480.0f - box_size.y) < (location.x + direction.y))
	//{
	//	direction.y *= -1.0f;
	//}*/
	////���݂̈ʒu���W�ɑ��������Z����
	//location += direction;

}

//�A�j���[�V��������
void Harpy::AnimationControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 30)
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