// Derived class for microglia-specific behavior

#ifndef MICROGLIA_H
#define MICROGLIA_H

#include "Agent.h"
#include "intracellular/IntracellularModel.h"
#include "fields/Vector2D.h"

class Field;  // Forward declaration

class Microglia : public Agent {
public:
    Microglia(double x, double y, double chemotacticCoeff);
    virtual ~Microglia() = default;
    
    void update(double dt) override;
    void move(const Vector2D &direction, double dt) override;
    
    // Sense local ATP and update intracellular state
    void senseAndReact(const Field &atpField);

private:
    double chemotacticCoeff;
    IntracellularModel intracellular; // Detailed receptor kinetics model
};

#endif // MICROGLIA_H
