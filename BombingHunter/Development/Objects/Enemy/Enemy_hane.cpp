#include "Enemy_hane.h"
#include "DxLib.h"

//コンストラクタ
Enemy_hane::Enemy_hane() : animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Enemy_hane::~Enemy_hane()
{

}

//初期化処理
void Enemy_hane::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/ハネテキ1.png");
	animation[1] = LoadGraph("Resource/Images/ハネテキ2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハネテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];

	//初期進行方向の描画
	direction = Vector2D(1.0f);
}

//更新処理
void Enemy_hane::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Enemy_hane::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;

	//進行方向によって、反転状態を決定する
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	__super::Draw();
}

//終了時処理
void Enemy_hane::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy_hane::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
	/*DeleteObject;*/
}

//移動処理
void Enemy_hane::Movement()
{
	location.x += 1.0;
	////画面端に到達したら、進行方向を反転する
	//if (((location.x + direction.x) < box_size.x) || (640.0f - box_size.x) < (location.x + direction.x))
	//{
	//	direction.x *= -1.0f;
	//}
	///*if (((location.y + direction.y) < box_size.y) || (480.0f - box_size.y) < (location.x + direction.y))
	//{
	//	direction.y *= -1.0f;
	//}*/
	////現在の位置座標に速さを加算する
	//location += direction;

}

//アニメーション制御
void Enemy_hane::AnimationControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 30)
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