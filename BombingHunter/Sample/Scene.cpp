#include "Scene.h"

#include "../Object/Player/Player.h"

//�R���X�g���N�^
Scene::Scene() :objects()
{

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
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 240.0f));
}

//�X�V����
void Scene::Draw() const
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
}