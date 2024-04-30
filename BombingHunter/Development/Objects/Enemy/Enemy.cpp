//#include "Enemy.h"
//#include "DxLib.h"
//
//Enemy::Enemy() :animation_count(0), direction(0.0f)
//{
//	animation[0] = NULL;
//	animation[1] = NULL;
//}
//
//Enemy::~Enemy()
//{
//
//}
//
////初期化処理
//void Enemy::Initialize()
//{
//	//画像の読み込み
//	animation[0] = LoadGraph("Resource/Images/ハコテキ1.png");
//	animation[1] = LoadGraph("Resource/Images/ハコテキ2.png");
//
//	//エラーチェック
//	if (animation[0] == -1 || animation[1] == -1)
//	{
//		throw()
//	}
//}

#include "Enemy.h"
#include "DxLib.h"

//コンストラクタ
Enemy::Enemy() : animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Enemy::~Enemy()
{

}

//初期化処理
void Enemy::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/ハコテキ1.png");
	animation[1] = LoadGraph("Resource/Images/ハコテキ2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハコテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	scale = 64.0f;

	//初期画像の設定
	image = animation[0];
}

//更新処理
void Enemy::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Enemy::Draw() const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, filp_flag);

	//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);
	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//終了時処理
void Enemy::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
}

//移動処理
void Enemy::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	velocity.x = 1.0;
	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy::AnimationControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}