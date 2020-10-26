#pragma once
#include <vector>

struct BaseAttribute;
class Blueprint;

class BaseDesigner
{
public:
	virtual void HandleAttribute(BaseAttribute& aAttribute);
};

template<typename T>
class Designer : public BaseDesigner
{
public:
	virtual T Design(const Blueprint& aBlueprint) = 0;

};


