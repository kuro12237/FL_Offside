#include "Baggage.h"
#include "Player/PlayerManager.h"

void Baggage::Init() {
  category_ = VAR_NAME(Baggage);

  terrainY_ = 1.0f;

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

void Baggage::Update() {

  auto input = CLEYERA::Manager::InputManager::GetInstance();

  Math::Vector::Vec2 joy = input->JoyRPos();

  force_.x = joy.x * 0.1f;
  force_.y = joy.y * 0.1f;

  this->TransformUpdate();
}

void Baggage::OnCollision(
    std::weak_ptr<CLEYERA::Component::ObjectComponent> other) {
  auto obj = other.lock();
  if (!obj)
    return;

  if (obj == std::dynamic_pointer_cast<NormalBlock>(obj)) {

    auto aabb =
        std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
            obj->GetCollider().lock());
    // 押し出し
    this->translate_ += aabb->GetAABB().push;
    std::queue<CLEYERA::Util::Collider::HitDirection> dir = this->hitDirection_;

    while (!dir.empty()) {
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Bottom) {
        velocity_.y = 0.0f;
      }
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Top) {
        velocity_.y = 0.0f;
      }
      dir.pop();
    }

    gameObject_->Update();

    return;
  }
  if (obj == std::dynamic_pointer_cast<PlayerCore>(obj)) {

    auto aabb =
        std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
            obj->GetCollider().lock());
    // 押し出し
    std::queue<CLEYERA::Util::Collider::HitDirection> dir = this->hitDirection_;

    while (!dir.empty()) {
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Bottom) {
        velocity_.y = 0.0f;

        this->translate_ += aabb->GetAABB().push;
      }else if (dir.front() == CLEYERA::Util::Collider::HitDirection::Top) {
        velocity_.y = 0.0f;
      } else {

        this->translate_ += aabb->GetAABB().push;
      }
      dir.pop();
    }

    gameObject_->Update();

    return;
  }
  if (obj == std::dynamic_pointer_cast<Baggage>(obj)) {

    auto aabb =
        std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
            obj->GetCollider().lock());
    // 押し出し
    this->translate_ += aabb->GetAABB().push;
    std::queue<CLEYERA::Util::Collider::HitDirection> dir = this->hitDirection_;

    while (!dir.empty()) {
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Bottom) {
        velocity_.y = 0.0f;
      }
      if (dir.front() == CLEYERA::Util::Collider::HitDirection::Top) {
        velocity_.y = 0.0f;
      }
      dir.pop();
    }

    gameObject_->Update();

    return;
  }
}