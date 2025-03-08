#include "fields/Field.h"
#include "fields/Vector2D.h"
#include <cassert>
#include <iostream>

int main() {
    Field testField(10, 10, 0.1, 0.01, 0.001);
    testField.setSource(5, 5, 1.0);
    testField.update();
    Vector2D pos(5.0, 5.0);
    double value = testField.getValue(pos);
    std::cout << "Field value at center: " << value << std::endl;
    assert(value > 0);
    return 0;
}
