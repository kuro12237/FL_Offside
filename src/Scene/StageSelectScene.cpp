#include "StageSelectScene.h"

void StageSelectScene::Init()
{

	uint32_t model = CLEYERA::Manager::ModelManager::GetInstance()->LoadModel(
		"Resources/Model/Terrain/", "Terrain");
	auto terrain = CLEYERA::Manager::Terrain::GetInstance();
	terrain->Init();
}

void StageSelectScene::Update([[maybe_unused]] CLEYERA::Manager::SceneManager* ins)
{

}
