// Microglia-specific functions (movement, state update)

#include "agents/Microglia.h"
#include "fields/Field.h"

Microglia::Microglia(double x, double y, double chemotacticCoeff)
    : Agent(x, y), chemotacticCoeff(chemotacticCoeff) {
    intracellular = IntracellularModel();
}

void Microglia::update(double dt) {
    // Update internal state if needed (currently handled in senseAndReact)
}

void Microglia::move(const Vector2D &direction, double dt) {
    Vector2D normalizedDir = direction.normalized();
    double factor = intracellular.getChemotacticFactor();
    position = position + normalizedDir * chemotacticCoeff * factor * dt;
}

void Microglia::senseAndReact(const Field &atpField) {
    double atpConcentration = atpField.getValue(position);
    intracellular.update(0.001, atpConcentration); // Update with a small dt
}
