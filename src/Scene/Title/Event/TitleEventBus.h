#pragma once
#include <functional>
#include <unordered_map>
#include <typeindex>
#include <vector>


class EventBus {
public:
    template<typename EventType>
    void Subscribe(std::function<void(const EventType&)> listener) {
        auto& list = listeners_[typeid(EventType)];
        list.push_back([=](const void* e) {
            listener(*static_cast<const EventType*>(e));
            });
    }

    template<typename EventType>
    void Publish(const EventType& event) {
        auto it = listeners_.find(typeid(EventType));
        if (it == listeners_.end()) return;
        for (auto& fn : it->second) fn(&event);
    }

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const void*)>>> listeners_;
};