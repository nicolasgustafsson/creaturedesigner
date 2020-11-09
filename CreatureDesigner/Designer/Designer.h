#pragma once
#include <vector>
#include <memory>
#include "Operation/Operation.h"

class Sketch;

class DesignerBase
{
protected:
	template<typename TOperation>
	void AddOperation()
	{
		myOperations.push_back(std::make_unique<TOperation>());
	}

	std::vector<std::unique_ptr<Operation>> myOperations;
};

template<typename T>
class Designer : public DesignerBase
{
public:
	virtual T Design(const Sketch& aSketch) const;
};

template<typename T>
T Designer<T>::Design(const Sketch& aSketch) const
{
	for (auto& operation : myOperations)
	{
		if (operation->IsEligible(aSketch))
		{
			//todo: do something with this?
			Sketch wow = aSketch;
			operation->Perform(wow);
		}
	}

	//todo: actually 
	return {};
}

