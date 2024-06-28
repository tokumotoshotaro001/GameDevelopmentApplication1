#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER
#define enemy (20)
#define enemy_hane (30)
#define harpy (50)
#define enemy_bullet (60)


//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{
protected:
	Vector2D location;
	Vector2D box_size;
	double radian;
	int image;
	int sound;
	int type;

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

	int GetType();

	void SetType(int object_type);

	virtual bool DeleteObject();
};

