#pragma once
#include"Camera/PlayerCamera.h"

class PlayerManager {
public:
  PlayerManager() {};
  ~PlayerManager() {};

  void Init();

  void Update();

private:

	std::unique_ptr<PlayerCamera> camera_ = nullptr;
};