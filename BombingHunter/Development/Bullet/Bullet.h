#pragma once
#include "../Objects/GameObject.h"
#include "../../Scene/Scene.h"
class Bullet : public GameObject
{
private:
    int images;
    int se;
    int hit;

private:
    //int animation[2];  //アニメーション画像
    //int animation_count; //アニメーション時間
    Vector2D direction;  //進行方向

public:
    Bullet();
    ~Bullet();

    virtual void Initialize() override;  //初期化処理
    virtual void Update() override;    //更新処理
    virtual void Draw() const override; //描画処理
    virtual void Finalize() override;  //修了時処理


    //あ有判定通知処理
    virtual void OnHitCollision(GameObject* hit_object) override;
  /*  virtual bool  DeleteObject()  override;*/

private:
    //移動処理
    void Movement();
    //アニメーション制御
 /*    void AnimeControl(); */
};