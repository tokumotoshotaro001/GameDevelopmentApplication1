#pragma once

#include "../GameObject.h"
class Enemy_hane :public GameObject
{
private:
	int animation[2];
	int animation_count;
	Vector2D direction;

public:
	Enemy_hane();
	~Enemy_hane();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	void Movement();
	void AnimationControl();
};

