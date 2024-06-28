#include "Bullet.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Bullet::Bullet () : direction(0.0f), images(NULL), se(), hit()
{

}

//デストラクタ
Bullet::~Bullet()
{

}

//初期化処理
void Bullet::Initialize()
{
    se = LoadSoundMem("Resource/Sounds/teki_gahee.wav");
    //画像の読み込み
    images = LoadGraph("Resource/Images/爆弾.png");
    //大きさの設定
    box_size = 35.0f;
    //初期画像の設定
    image = images;

    //初期進行方向の設定
    if (InputControl::GetKey(KEY_INPUT_LEFT))
    {
        radian = 2.0;
        direction = Vector2D(-1.5f, 1.0f);
    }
    else if (InputControl::GetKey(KEY_INPUT_RIGHT))
    {
        radian = 1.0;
        direction = Vector2D(1.5f, 1.0f);
    }
    else
    {
        radian = DX_PI_F / 2;
        direction = Vector2D(0.0f, 1.0f);
    }

}

//更新処理
void Bullet::Update()
{
    //移動処理
    Movement();
    //アニメーション制御
    //AnimeControl();
}

//描画処理
void Bullet::Draw()const
{

    //爆弾画像の描画
    DrawRotaGraphF(location.x, location.y, 0.3, radian, image, TRUE, 0);

    //デバッグ用
#if _DEBUG
    //当たり判定の可視化
    Vector2D box_collision_upper_left = location - (box_size / 2.0f);
    Vector2D box_collision_lower_right = location + (box_size / 2.0f);

    DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y,
        box_collision_lower_right.x, box_collision_lower_right.y,
        GetColor(255, 0, 0), FALSE);

#endif
}


//修了時処理
void Bullet::Finalize()
{
    //使用した画像を解放する
    DeleteGraph(images);
    /*DeleteGraph(animation[1]);*/
}


//当たり判定通知処理
void Bullet::OnHitCollision(GameObject* hit_object)
{
    //あたった時の処理
    hit = true;
}

//bool Bullet::DeleteObject()
//{
//    bool ret = false;
//
//    if (location.x > 640.0f + box_size.x  location.x < 0.0f - box_size.x  hit == true)
//    {
//        ret = true;
//    }
//
//    return ret;
//}

//移動処理
void Bullet::Movement()
{
    //下へ移動し続ける
    location += direction;

}
