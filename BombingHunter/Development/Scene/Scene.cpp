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

//コンストラクタ
Scene::Scene() :objects(),frame(0),count(), count1(), count2(), count3(), Enemy_count(4), Enemy_count1(4), Enemy_count2(4),cha(),cha1()
{
	for (int i = 0; i < 2; i++)
	{
		BGM[i] = NULL;
	}
}

//デストラクタ
Scene::~Scene()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	//BGM生成
	BGM[0] = LoadSoundMem("Resource/Images/BGM_arrows.wav");

	//BGM再生処理
	PlaySoundMem(BGM[0], DX_PLAYTYPE_LOOP, TRUE);

	back_image = LoadGraph("Resource/Images/背景2.png");

	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 70.0f));
	
	//ハコテキの確率
	count = GetRand(100);

	//ハネテキの確立
	count1 = GetRand(100);

	//ハーピーの確立
	count2 = GetRand(100);


}

//更新処理
void Scene::Update()
{
	frame++;

	//テキ生成
	if (frame>=180)
	{
		//ハコテキ生成
		if (Enemy_count > 0)
		{
			if (count <= 40)
			{
				CreateObject<Enemy>(Vector2D(0.0f, 390.0f));
			}
		}

		//ハネテキ生成
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

		//ハーピー生成
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

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//当たり判定チェック
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

	//オブジェクト消去
	/*for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->GetType() == true)
		{
			DeleteObject;
		}
	}*/

	//弾を出す処理
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bullet>(objects[0]->GetLocation());
	}

	
}

//描画処理
void Scene::Draw() const
{
	DrawRotaGraph(300.0, 130.0, 1.0,0.0, back_image, TRUE);

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//終了時処理
void Scene::Finalize()
{
	//動的配列がからなら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//動的配列の開放
	objects.clear();

	//BGM削除処理
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

