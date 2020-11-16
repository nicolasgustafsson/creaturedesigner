#pragma once
#include <vector>
#include <memory>
#include "Operation/Operation.h"
#include <iostream>

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

	std::unique_ptr<Operation> myCreateOperation;
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
	Sketch sketchInProgress = aSketch;
	for (auto& operation : myOperations)
	{
		if (operation->IsEligible(sketchInProgress))
		{
			operation->Perform(sketchInProgress);
		}
	}

	//todo: handle failure gracefully
	if (!sketchInProgress.ContainsAttribute<SDesignedObjectAttribute<T>>())
	{
		std::cout << "fail" << std::endl;
		return {};
	}

	return sketchInProgress.GetAttribute<SDesignedObjectAttribute<T>>()->FinishedDesign;
}

