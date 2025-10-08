#pragma once
#include"CLEYERA.h"
#include"Block/DFBlock/NormalBlock.h"

/// <summary>
/// 荷物
/// </summary>
class Baggage:public CLEYERA::Component::ObjectComponent {
public:
  Baggage() {};
  ~Baggage() {};

  void Init() override;
  void Update() override;

    void OnCollision(std::weak_ptr<CLEYERA::Component::ObjectComponent> other);


private:
};
