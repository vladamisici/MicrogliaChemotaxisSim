// Implements intracellular ODE models (receptor kinetics, etc.)

#include "intracellular/IntracellularModel.h"
#include <algorithm>

IntracellularModel::IntracellularModel()
    : receptorActivation(0.0), bindingRate(0.1), unbindingRate(0.05) {}

void IntracellularModel::update(double dt, double atpConcentration) {
    // Simple kinetics: dR/dt = bindingRate * [ATP] - unbindingRate * R
    double dR = bindingRate * atpConcentration - unbindingRate * receptorActivation;
    receptorActivation += dR * dt;
    receptorActivation = std::clamp(receptorActivation, 0.0, 1.0);
}

double IntracellularModel::getChemotacticFactor() const {
    return receptorActivation;
}

double IntracellularModel::getReceptorActivation() const {
    return receptorActivation;
}
