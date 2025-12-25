#include "Action.h"

Action::Action(const std::string& name, ActionType type)
    : m_name(name), m_type(type) {
}

Action::Action()
    : m_name("NONE"), m_type(ActionType::Pressed) {
}

const std::string& Action::getName() const { return m_name; }
ActionType Action::getType() const { return m_type; }