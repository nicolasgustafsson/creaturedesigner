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

    //TODO MORE CONTENT AND PATHFINDING

    CreatureDesigner designer;

    srand(std::time(nullptr));
    auto creature = designer.Design(sketch);

    std::cout << "CREATURE THING:\nRed: " << creature.myColor.R << "\nGreen: " << creature.myColor.G << "\nBlue: " << creature.myColor.B;

    std::cin.get();
}