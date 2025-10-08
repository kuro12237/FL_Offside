#include "BaggageManager.h"

void BaggageManager::Init() {

  objManager_ = CLEYERA::Manager::ObjectManager::GetInstance();

  BaggageSizeData baggage;
  baggage.name = VAR_NAME(Baggage);
  baggage.size = this->GetCategorySizeFunc_(baggage.name);

  this->CreateBaggageObjects<Baggage>(baggage);

};

void BaggageManager::Update() {};