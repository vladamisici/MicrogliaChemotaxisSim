// Real-time visualization tools (VTK/OpenGL interfaces)

#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "fields/Field.h"
#include "agents/Microglia.h"
#include <vector>

class Visualization {
public:
    Visualization();
    ~Visualization() = default;

    // Render the simulation state (console output for now)
    void render(const Field &atpField, const std::vector<Microglia> &microglia);
};

#endif // VISUALIZATION_H
