//

#include <iostream>
#include <istream>
#include "Sketch/Sketch.h"
#include "Attribute/Attribute.h"
#include <memory>
#include <random>
#include <ctime>
#include "Creature/CreatureDesigner.h"

int main()
{
    Sketch sketch;
    auto colorAttribute = std::make_shared<SEmotionAttribute>();

    //colorAttribute->Emotion = EEmotion::Happy;

	//sketch.myAttributes.emplace_back(std::move(colorAttribute));









    //what we need do
    //Add more attribute and operations
    //







    /*Design creature
    *     Figure out what creature is supposed to be
    *         Figure out what meaningful variation between creatures is
    *           Moves, (needs designer)
	*           1-2 types,
	*           Real life anchor,
	*           Height,
	*           Weight,
	*           Ability,
	*           Gender ratio,
	*           Stats
	*               (HP, atk, defense, sp. atk, sp. defense, speed),
	*           Evolutions/prevolutions
	*           Name
    */













    //TODO: FINISH MOVE OPERATIONS















    CreatureDesigner designer;

    srand(std::time(nullptr));
    auto creature = designer.Design(sketch);

    std::cout << "CREATURE THING:\nRed: " << creature.myColor.R << "\nGreen: " << creature.myColor.G << "\nBlue: " << creature.myColor.B;

    std::cin.get();
}