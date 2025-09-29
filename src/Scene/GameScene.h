#pragma once

#include "CLEYERA.h"

#include "Player/PlayerManager.h"
#include "Sun/Sun.h"
#include"../Util/SceneLoader.h"

class GameScene : public CLEYERA::Component::SceneComponent {
public:
  GameScene() {};
  ~GameScene() {};

  void Init() override;
  void Update(CLEYERA::Manager::SceneManager *ins) override;

private:
  std::unique_ptr<Sun> sun_ = nullptr;
  std::unique_ptr<PlayerManager> player_ = nullptr;

  std::unique_ptr<SceneLoader> loader_ = nullptr;
};