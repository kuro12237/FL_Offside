#include "BaggageManager.h"

void BaggageManager::Init() {

  objManager_ = CLEYERA::Manager::ObjectManager::GetInstance();

  BaggageSizeData baggage;
  baggage.name = VAR_NAME(Baggage);
  baggage.size = this->GetCategorySizeFunc_(baggage.name);

  this->CreateBaggageObjects<Baggage>(baggage);

};

void BaggageManager::Update() {
  if (ImGui::Button("spawn")) {
  
    BaggageSizeData baggage;
    baggage.name = VAR_NAME(Baggage);
    baggage.size = this->GetCategorySizeFunc_(baggage.name);

     auto obj = objManager_->CreateObject<Baggage>(baggage.name, std::make_shared<Baggage>());
    baggages_[baggage.name].push_back(obj);
  }


};