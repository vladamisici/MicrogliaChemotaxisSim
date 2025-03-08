// Code to visualize simulation data in real time

#include "visualization/Visualization.h"
#include <iostream>

Visualization::Visualization() {}

void Visualization::render(const Field &atpField, const std::vector<Microglia> &microglia) {
    std::cout << "Rendering simulation state:" << std::endl;
    for (const auto &m : microglia) {
        Vector2D pos = m.getPosition();
        std::cout << "Microglia at (" << pos.x << ", " << pos.y << ")" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}
