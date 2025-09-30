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
  aabb->GetAABB_().min = {-1.0f, -1.0f, -1.0f};

}

void PlayerCore::Update() {}

void PlayerCore::OnCollision(
    std::weak_ptr<CLEYERA::Component::ObjectComponent> other) {

}

void PlayerCore::MoveCommand() {

  auto input = CLEYERA::Manager::InputManager::GetInstance();

  Math::Vector::Vec2 joy = input->JoyLPos();

  translate_.x += joy.x * speed_;
}
