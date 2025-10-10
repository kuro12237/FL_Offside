#pragma once
#include "Baggage.h"

struct BaggageSizeData {
  std::string name = "";
  size_t size = 0;
};

/// <summary>
/// 荷物管理クラス
/// </summary>
class BaggageManager {
public:
  BaggageManager() {};
  ~BaggageManager() {};

  void Init();

  void Update();

  void SetGetCategorySizeFunc(std::function<size_t(std::string)> func) {
    GetCategorySizeFunc_ = func;
  }

private:
  /// <summary>
  /// objctのインスタンス数に応じて作る関数
  /// </summary>
  template <typename T> void CreateBaggageObjects(BaggageSizeData data);

  size_t max_ = 1;

  std::function<size_t(std::string)> GetCategorySizeFunc_;

  std::unordered_map<std::string, std::vector<std::weak_ptr<Baggage>>>
      baggages_;
  CLEYERA::Manager::ObjectManager *objManager_ = nullptr;
};

template <typename T>
inline void BaggageManager::CreateBaggageObjects(BaggageSizeData data) {
  for (size_t i = 0; i < static_cast<size_t>(data.size); i++) {
    auto obj = objManager_->CreateObject<T>(data.name, std::make_shared<T>());
    baggages_[data.name].push_back(obj);
  }
}
