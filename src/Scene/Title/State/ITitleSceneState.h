#pragma once

#include "../Event/TitleEventBus.h"

// �O���錾
class TitleScene;

class ITitleSceneState {

public:

	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ITitleSceneState() = default;

	/// <summary>
	/// �J�n����
	/// </summary>
	virtual void Enter(TitleScene& scene) = 0;

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// �I������
	/// </summary>
	virtual void Exit() = 0;

protected:

	TitleScene* ownerScene_ = nullptr;

};