#pragma once

#include <vector>
#include <string>
#include "../Objects/GameObject.h"

class Scene :public GameObject
{
private:
	int BGM[2];
	int back_image;
	int frame;
	int count;
	int count1;
	int count2;
	int count3;
	int Enemy_count;
	int Enemy_count1;
	int Enemy_count2;
	int cha;
	int cha1;


	std::vector<GameObject*> objects;

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	void HitCheckObject(GameObject* a, GameObject* b);
	//オブジェクト生成処理
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}

		//初期化処理
		new_object->Initialize();
		//位置情報の設定
		new_object->SetLocation(location);

		//オブジェクトリストの追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;

		bool DeleteObject();
	}
};

