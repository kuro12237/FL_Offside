#pragma once
#include "IPlayerCommand.h"
#include "Player/PlayerCore/PlayerCore.h"


class PlayerCommandJump : public IPlayerCommand {
public:
  PlayerCommandJump() {};
  ~PlayerCommandJump() {};

  void Execute(PlayerCore *p);

private:
};