#pragma once
#include "../GameObject.h"
#include "../../Scene/Scene.h"
class Enemy_bullet : public GameObject
{
private:
    int images;
    int scale;
private:
    //int animation[2];  //�A�j���[�V�����摜
    //int animation_count; //�A�j���[�V��������
    Vector2D direction;  //�i�s����

public:
    Enemy_bullet();
    ~Enemy_bullet();

    virtual void Initialize() override;  //����������
    virtual void Update() override;    //�X�V����
    virtual void Draw() const override; //�`�揈��
    virtual void Finalize() override;  //�C��������



    //���L����ʒm����
    virtual void OnHitCollision(GameObject* hit_object) override;

private:
    //�ړ�����
    void Movement();
    //�A�j���[�V��������
   /* void AnimeControl();*/
};