#pragma once
#include <string>

enum class ActionType {
    Pressed,
    Released,
    Moved,
    Wheel
};

class Action {
    std::string m_name;
    ActionType  m_type;

public:
    int mouseX = 0;
    int mouseY = 0;
    int mouseDeltaX = 0;
    int mouseDeltaY = 0;
    int wheelDelta = 0;

    Action(const std::string& name, ActionType type);
    Action();

    const std::string& getName() const;
    ActionType getType() const;
};