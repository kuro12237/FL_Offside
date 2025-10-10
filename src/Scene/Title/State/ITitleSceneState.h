#pragma once

#include "../Event/TitleEventBus.h"

// 前方宣言
class TitleScene;

class ITitleSceneState {

public:

	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ITitleSceneState() = default;

	/// <summary>
	/// 開始処理
	/// </summary>
	virtual void Enter(TitleScene& scene) = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Exit() = 0;

protected:

	TitleScene* ownerScene_ = nullptr;

};