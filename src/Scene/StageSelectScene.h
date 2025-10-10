#pragma once

#include "CLEYERA.h"

/* ステージセレクトシーンシーン */
class StageSelectScene : public CLEYERA::Component::SceneComponent {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	StageSelectScene() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~StageSelectScene() = default;

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(CLEYERA::Manager::SceneManager* ins) override;


private:


};
