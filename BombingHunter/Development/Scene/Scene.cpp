#include "Scene.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/Enemy_hane.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Bullet/Bullet.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
#include"../Utility/Vector2D.h"

#define D_PIVOT_CENTER

//�R���X�g���N�^
Scene::Scene() :objects(),frame(0),count(), count1(), count2(), count3(), Enemy_count(4), Enemy_count1(4), Enemy_count2(4),cha(),cha1()
{
	for (int i = 0; i < 2; i++)
	{
		BGM[i] = NULL;
	}
}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	//BGM����
	BGM[0] = LoadSoundMem("Resource/Images/BGM_arrows.wav");

	//BGM�Đ�����
	PlaySoundMem(BGM[0], DX_PLAYTYPE_LOOP, TRUE);

	back_image = LoadGraph("Resource/Images/�w�i2.png");

	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 70.0f));
	
	//�n�R�e�L�̊m��
	count = GetRand(100);

	//�n�l�e�L�̊m��
	count1 = GetRand(100);

	//�n�[�s�[�̊m��
	count2 = GetRand(100);


}

//�X�V����
void Scene::Update()
{
	frame++;

	//�e�L����
	if (frame>=180)
	{
		//�n�R�e�L����
		if (Enemy_count > 0)
		{
			if (count <= 40)
			{
				CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
			}
		}

		//�n�l�e�L����
		if (Enemy_count1 > 0)
		{
			if (count1 <= 30)
			{
				if (cha == 0)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 120.0f));
				}
				else if (cha == 1)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 200.0f));
				}
				else if (cha == 2)
				{
					CreateObject<Enemy_hane>(Vector2D(0.0f, 260.0f));
				}
				Enemy_count1--;
			}
		}

		//�n�[�s�[����
		if (Enemy_count2 > 0)
		{
			if (count1 <= 50)
			{
				if (cha == 0)
				{
					CreateObject<Harpy>(Vector2D(0.0f, 200.0f));
				}
				else if (cha == 1)
				{
					CreateObject<Harpy>(Vector2D(0.0f, 120.0f));
				}
				else if (cha == 2)
				{
					CreateObject<Harpy>(Vector2D(0.0f, 260.0f));
				}
				Enemy_count2--;
			}
		}

		count = GetRand(100);
		count1 = GetRand(100);
		count2 = GetRand(100);

		cha = GetRand(2);
		cha1 = GetRand(2);

		frame = 0;
	}

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//�����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			if (objects[i]->GetType() != objects[j]->GetType())
			{
				HitCheckObject(objects[i], objects[j]);
			}
		}
	}

	//�I�u�W�F�N�g����
	/*for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->GetType() == true)
		{
			DeleteObject;
		}
	}*/

	//�e���o������
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bullet>(objects[0]->GetLocation());
	}

	
}

//�`�揈��
void Scene::Draw() const
{
	DrawRotaGraph(300.0, 130.0, 1.0,0.0, back_image, TRUE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//�I��������
void Scene::Finalize()
{
	//���I�z�񂪂���Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�z��̊J��
	objects.clear();

	//BGM�폜����
	DeleteSoundMem(BGM[0]);
}

#ifdef D_PIVOT_CENTER


void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	Vector2D diff = a->GetLocation() - b->GetLocation();

	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else

void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > a->GetLocation().x) &&
		(a_lower_right.y > a->GetLocation().y))
	{
		a->OnHitCollision(b);
		a->OnHitCollision(b);
	}
}
#endif D_PIVOT_CNTER

