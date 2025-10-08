#pragma once
#include"CLEYERA.h"

class StartHouse : public CLEYERA::Component::ObjectComponent{
public:
  StartHouse() {};
  ~StartHouse() {};

  void Init() override;
  void Update() override;

private:
};


