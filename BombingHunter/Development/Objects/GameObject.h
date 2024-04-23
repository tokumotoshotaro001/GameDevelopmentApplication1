#pragma once

#include "../Utility/Vector2D.h"

//ゲームオブジェクト基底クラス
class GameObject
{
protected:
	Vector2D location;
	double scale;
	double radian;
	int image;
	int sound;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object);

	//位置情報取得処理
	Vector2D GetLocation() const;
	//位置情報変更処理
	void SetLocation(const Vector2D& location);
};

