#pragma once

#include "CLEYERA.h"

/* タイトルシーン */
class TitleScene : public CLEYERA::Component::SceneComponent {

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleScene() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene() = default;

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

