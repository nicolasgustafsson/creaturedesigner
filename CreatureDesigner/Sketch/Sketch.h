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
	const TAttribute* GetAttribute() const;

	std::vector<std::shared_ptr<const SAttribute>> myAttributes;
};

template<typename TAttribute>
bool Sketch::ContainsAttribute() const
{
	return GetAttribute<TAttribute>() != nullptr;
}


template<typename TAttribute>
const TAttribute* Sketch::GetAttribute() const
{
	auto it = std::find_if(myAttributes.begin(), myAttributes.end(), [](const auto& aAttribute) { return dynamic_cast<const TAttribute*>(aAttribute.get()) != nullptr; });
	
	if (it == myAttributes.end())
		return nullptr;

	return static_cast<const TAttribute*>(it->get());
}

