#pragma once

#include "CLEYERA.h"

/* �^�C�g���V�[�� */
class TitleScene : public CLEYERA::Component::SceneComponent {

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TitleScene() = default;

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~TitleScene() = default;

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

