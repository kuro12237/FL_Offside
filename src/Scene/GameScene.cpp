#include "GameScene.h"

void GameScene::Init() {
  auto objM = CLEYERA::Manager::ObjectManager::GetInstance();

	loader_ = std::make_unique<SceneLoader>();
  loader_->LoadFile("GameScene");

  sun_ = std::make_unique<Sun>();
  sun_->Init();

  player_ = std::make_unique<PlayerManager>();
  player_->Init();

  loader_->SettingData();
}

void GameScene::Update(CLEYERA::Manager::SceneManager *ins) {
  player_->Update();
  sun_->Update();
}
