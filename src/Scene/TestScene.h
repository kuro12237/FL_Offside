#pragma once

#include "CLEYERA.h"


#include"TestObject/TestObject.h"
#include"TestObject/TestLight.h"
#include"TestObject/TestCamera.h"

class TestScene : public CLEYERA::Component::SceneComponent {
public:
  TestScene() {};
  ~TestScene() {};

  void Init() override;
  void Update(CLEYERA::Manager::SceneManager *ins) override;


private:
  std::shared_ptr<TestCamera> testCamera_ = nullptr;
	std::unique_ptr<TestPointLight> light_ = nullptr;
  std::vector<std::weak_ptr<TestObj>> testObj_;

};