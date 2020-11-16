#pragma once
#include <memory>
#include <vector>
#include "Attribute/Attribute.h"

class Sketch
{
public:
	template<typename TAttribute>
	bool ContainsAttribute() const;

	template<typename TAttribute>
	void AddAttribute(const TAttribute& aAttribute);

	template<typename TAttribute>
	std::shared_ptr<const TAttribute> GetAttribute() const;

	std::vector<std::shared_ptr<const SAttribute>> myAttributes;
};

template<typename TAttribute>
bool Sketch::ContainsAttribute() const
{
	return GetAttribute<TAttribute>() != nullptr;
}

template<typename TAttribute>
void Sketch::AddAttribute(const TAttribute& aAttribute)
{
	myAttributes.push_back(std::make_shared<TAttribute>(aAttribute));
}

template<typename TAttribute>
std::shared_ptr<const TAttribute> Sketch::GetAttribute() const
{
	auto it = std::find_if(myAttributes.begin(), myAttributes.end(), [](const auto& aAttribute) { return dynamic_cast<const TAttribute*>(aAttribute.get()) != nullptr; });
	
	if (it == myAttributes.end())
		return nullptr;

	return std::static_pointer_cast<const TAttribute>(*it);
}

