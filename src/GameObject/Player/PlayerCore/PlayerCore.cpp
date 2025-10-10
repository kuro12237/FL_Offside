#include "PlayerCore.h"

#include "Baggage/BaggageManager.h"

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
  aabb->GetAABB_().max = {1.0f, 2.0f, 1.0f};
  aabb->GetAABB_().min = {-1.0f, -2.0f, -1.0f};
  terrainY_ = 1.0f;
}

void PlayerCore::Update() {

  this->TransformUpdate();
}

void PlayerCore::OnCollision(
    std::weak_ptr<CLEYERA::Component::ObjectComponent> other) {
  auto obj = other.lock();
  if (!obj)
    return;
  auto aabb = std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
      obj->GetCollider().lock());

  // 積み木
  if (obj == std::dynamic_pointer_cast<NormalBlock>(obj)) {

    this->translate_ += aabb->GetAABB().push;

    std::queue<CLEYERA::Util::Collider::HitDirection> dir = this->hitDirection_;
    while (!dir.empty()) {
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Bottom ||
          dir.front() == CLEYERA::Util::Collider::HitDirection::Top) {
        velocity_.y = 0.0f;
      }
      dir.pop();
    }

    gameObject_->Update();
    return;
  }

  // 荷物
  if (obj == std::dynamic_pointer_cast<Baggage>(obj)) {
    auto baggage = std::dynamic_pointer_cast<Baggage>(obj);

    this->translate_ += aabb->GetAABB().push / 2.0f;

    std::queue<CLEYERA::Util::Collider::HitDirection> dir = this->hitDirection_;
    // 上下に当たってる時velo0
    while (!dir.empty()) {
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Bottom ||
          dir.front() == CLEYERA::Util::Collider::HitDirection::Top) {
        velocity_.y = 0.0f;
      }
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Left &&
          dir.front() == CLEYERA::Util::Collider::HitDirection::Right) {
 
      }
      dir.pop();
    }

    gameObject_->Update();
    return;
  }
}

void PlayerCore::MoveCommand() {

  auto input = CLEYERA::Manager::InputManager::GetInstance();
  Math::Vector::Vec2 joy = input->JoyLPos();

  force_.x = joy.x * speed_;

  auto dir = hitDirection_;

  while (!dir.empty()) {
    if (dir.front() == CLEYERA::Util::Collider::HitDirection::Left) {

      isRightMove_ = true;
    }
    if (dir.front() == CLEYERA::Util::Collider::HitDirection::Right) {

      isLeftMove_ = true;
    }
    dir.pop();
  }
}

void PlayerCore::JumpCommand() { force_.y = 1.0f; }
