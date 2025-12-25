#pragma once

#include "UIElement.h"
#include "TestUIElement.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <type_traits>

typedef std::shared_ptr<UIElement> UIElementPtr;
typedef std::vector<UIElementPtr> UIElementVec;
typedef std::unordered_map<std::string, UIElementVec> UIElementMap;

class UIManager {
	size_t m_uniqueIdIndex = 0;
	size_t m_totalUIElements = 0;
	UIElementVec m_uiElements;
	UIElementVec m_uiElementsToAdd;
	UIElementMap m_uiElementMap;
	int removeInactiveElements(UIElementVec &);
public:

	UIManager();
	UIElementVec& getUIElements();
	UIElementVec& getUIElements(const std::string& tag);
	template <typename T>
	T& addUIElement(const std::string & tag) {
		static_assert(std::is_base_of<UIElement, T>::value, "T must derive from UIElement");
		auto element = std::shared_ptr<T>(new T(m_uniqueIdIndex++, tag));
		T& ref = *element;
		m_uiElementsToAdd.push_back(element);
		return ref;
	}
	bool handleAction(const Action& action);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	
};


