//

#include <iostream>
#include <istream>
#include "Sketch/Sketch.h"
#include "Attribute/Attribute.h"
#include <memory>
#include "Creature/CreatureDesigner.h"

int main()
{
    Sketch sketch;
    auto colorAttribute = std::make_shared<SColorAttributeHSV>();

    colorAttribute->Hue = 0;

	sketch.myAttributes.emplace_back(std::move(colorAttribute));

    CreatureDesigner designer;

    designer.Design(sketch);

    std::cin.get();
}