#pragma once

#include "CLEYERA.h"

/* �X�e�[�W�Z���N�g�V�[���V�[�� */
class StageSelectScene : public CLEYERA::Component::SceneComponent {

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	StageSelectScene() = default;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~StageSelectScene() = default;

	/// <summary>
	/// ����������
	/// </summary>
	void Init() override;

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update(CLEYERA::Manager::SceneManager* ins) override;


private:


};
