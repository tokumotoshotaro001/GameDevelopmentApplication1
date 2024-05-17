#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER

//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{
protected:
	Vector2D location;
	Vector2D box_size;
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

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;
};

