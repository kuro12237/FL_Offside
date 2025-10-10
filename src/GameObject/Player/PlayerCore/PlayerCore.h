#pragma once
#include "../Base/IPlayer.h"
#include "CLEYERA.h"

#include "Command/IPlayerCommand.h"

#include "../../Block/DFBlock/NormalBlock.h"

class Baggage;

class PlayerCore : public IPlayer {
public:
  PlayerCore() {};
  ~PlayerCore() {};

  void Init() override;

  void Update() override;

  void OnCollision(std::weak_ptr<CLEYERA::Component::ObjectComponent> other);

#pragma region Command

  /// <summary>
  /// 移動コマンド
  /// </summary>
  void MoveCommand();

  void JumpCommand();

#pragma endregion

  #pragma region Get

  const Math::Vector::Vec3 &GetConstVelo() const { return velocity_; }
#pragma endregion


private:
  bool isRightMove_ = false;
  bool isLeftMove_ = false;
  float speed_ = 0.1f;
};
