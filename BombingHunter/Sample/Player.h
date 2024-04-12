#pragma once

#include "../GameObject.h"

class Player : public GameObject
{
private:
	int animation[2];
	int animation_const;
	int filp_flag;

public:
	Player();
	~Player();

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
	void AnimeControl();
};

