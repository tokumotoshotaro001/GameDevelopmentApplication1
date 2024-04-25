//#pragma once
//
//#include "../GameObject.h"
//
//class Enemy:public GameObject
//{
//private:
//	int animation[2];
//	int animation_count;
//	Vector2D direction;
//
//public:
//	Enemy();
//	~Enemy();
//
//	//����������
//	virtual void Initialize() override;
//	//�X�V����
//	virtual void Update() override;
//	//�`�揈��
//	virtual void Draw() const override;
//	//�I��������
//	virtual void Finalize() override;
//
//	//�����蔻��ʒm����
//	virtual void OnHitCollision(GameObject* hit_object) override;
//
//private:
//	//�ړ�����
//	void Movement();
//	//�A�j���[�V��������
//	void AnimetionControl();
//};
//

#pragma once

#include "../GameObject.h"

class Enemy : public GameObject
{
private:
	int animation[2];
	int animation_count;
	int filp_flag;

public:
	Enemy();
	~Enemy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();
};

