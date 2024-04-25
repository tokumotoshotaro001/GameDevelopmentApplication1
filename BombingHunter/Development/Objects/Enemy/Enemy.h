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
//	//初期化処理
//	virtual void Initialize() override;
//	//更新処理
//	virtual void Update() override;
//	//描画処理
//	virtual void Draw() const override;
//	//終了時処理
//	virtual void Finalize() override;
//
//	//当たり判定通知処理
//	virtual void OnHitCollision(GameObject* hit_object) override;
//
//private:
//	//移動処理
//	void Movement();
//	//アニメーション制御
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

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();
};

