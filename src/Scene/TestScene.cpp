#include "TestScene.h"

void TestScene::Init() {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto obj = objManager->CreateObject<TestObj>(VAR_NAME(TestObj),
                                               std::make_shared<TestObj>());

  light_ = std::make_unique<TestPointLight>();
  light_->Init();
  testCamera_ = std::make_shared<TestCamera>();
  testCamera_->Init();
}

void TestScene::Update(CLEYERA::Manager::SceneManager *ins) {

  // test
  light_->Update();

  testCamera_->Update();
};
