#include "PlayerManager.h"

void PlayerManager::Init() {

  camera_ = std::make_unique<PlayerCamera>();
  camera_->Init();
}

void PlayerManager::Update() {

camera_->Update(); }