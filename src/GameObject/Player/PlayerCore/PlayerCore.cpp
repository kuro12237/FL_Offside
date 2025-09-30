#include "PlayerCore.h"

void PlayerCore::Init() {
  category_ = VAR_NAME(PlayerCore);

  // コライダー作成
  CreateCollider(ColliderType::AABB);
  // 当たり判定関数セット
  collider_->SetHitCallFunc([this](std::weak_ptr<ObjectComponent> other) {
    this->OnCollision(other);
  });

  auto aabb = std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
      GetCollider().lock());
  aabb->GetAABB_().max = {1.0f, 1.0f, 1.0f};
  aabb->GetAABB_().min = {-1.0f, -2.0f, -1.0f};
  //terrainY_ = 1.0f;

}

void PlayerCore::Update() {
  //
  force_;
  translate_;
  this->TransformUpdate();
}

void PlayerCore::OnCollision(
    std::weak_ptr<CLEYERA::Component::ObjectComponent> other) {}

void PlayerCore::MoveCommand() {

  auto input = CLEYERA::Manager::InputManager::GetInstance();

  Math::Vector::Vec2 joy = input->JoyLPos();

  translate_.x += joy.x * speed_;
}

void PlayerCore::JumpCommand() {

  force_.y = 4.0f;
  // velocity_.y = 4.0f;
}
