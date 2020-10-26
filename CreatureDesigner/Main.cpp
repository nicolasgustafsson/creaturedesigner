// CreatureDesigner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include "Designers/CreatureDesigner.h"
#include "Attributes/Attributes.h"
struct SomeLargeData {
	SomeLargeData(int id_)
		: id(id_)
	{}
	int id;
	int arr[100];
};

struct SomeLargeData2 : public SomeLargeData
{
	SomeLargeData2(int id_)
		: SomeLargeData(id_)
	{}
};

int main()
{

	//std::vector<std::unique_ptr<BaseAttribute>> vec_byuniqptr;
	//
	//for (int i = 0; i < 43; ++i) {
	//	int id = rand() % 500000;
	//	// ...
	//	vec_byuniqptr.push_back(
	//		std::unique_ptr<BaseAttribute>(new ColorDescriptor(i)));
	//}

    CreatureDesigner designer;

    Blueprint blueprint;
	std::unique_ptr<ColorDescriptor> descriptor = std::make_unique<ColorDescriptor>();

    blueprint.myAttributes.emplace_back(std::move(descriptor));

    Creature myTotallyNotPokemon = designer.Design(blueprint);

    //std::cout << myTotallyNotPokemon.myColor << std::endl;

    std::cin.get();
}