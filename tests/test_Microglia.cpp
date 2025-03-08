#include "agents/Microglia.h"
#include "fields/Field.h"
#include "fields/Vector2D.h"
#include <cassert>
#include <iostream>

int main() {
    Field atpField(10, 10, 0.1, 0.01, 0.001);
    atpField.setSource(5, 5, 1.0);
    
    Microglia micro(2.0, 2.0, 0.05);
    micro.senseAndReact(atpField);
    Vector2D grad = atpField.getGradient(micro.getPosition());
    micro.move(grad, 0.001);
    Vector2D pos = micro.getPosition();
    std::cout << "Microglia new position: (" << pos.x << ", " << pos.y << ")" << std::endl;
    return 0;
}
