// ODE models for intracellular signaling (if needed)

#ifndef INTRACELLULAR_MODEL_H
#define INTRACELLULAR_MODEL_H

class IntracellularModel {
public:
    IntracellularModel();
    ~IntracellularModel() = default;
    
    // Update the intracellular model based on extracellular ATP concentration
    void update(double dt, double atpConcentration);

    // Return a factor that modulates chemotactic response (based on receptor activation)
    double getChemotacticFactor() const;

    // Optionally, expose receptor activation level for debugging
    double getReceptorActivation() const;

private:
    double receptorActivation;
    // Parameters for receptor kinetics (can be calibrated)
    double bindingRate;
    double unbindingRate;
};

#endif // INTRACELLULAR_MODEL_H
