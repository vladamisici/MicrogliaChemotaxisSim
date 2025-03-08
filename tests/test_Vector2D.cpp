#include "fields/Vector2D.h"
#include <cassert>
#include <iostream>

int main() {
    Vector2D v1(3.0, 4.0);
    assert(v1.magnitude() == 5.0);
    Vector2D v2 = v1.normalized();
    std::cout << "Normalized vector: (" << v2.x << ", " << v2.y << ")" << std::endl;
    return 0;
}
