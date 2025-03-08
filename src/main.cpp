#include <iostream>
#include <vector>
#include "fields/Field.h"
#include "agents/Microglia.h"
#include "solvers/RungeKuttaSolver.h"
#include "solvers/AdaptiveMeshSolver.h"
#include "region/RegionConfig.h"
#include "visualization/Visualization.h"

int main() {
    // Load region configuration from assets/config.ini
    RegionConfig regionConfig;
    regionConfig.loadConfig("assets/config.ini");

    int gridWidth = 100;
    int gridHeight = 100;
    double dt = 0.001;
    double simulationTime = 10.0;
    
    // Create ATP field with region-specific parameters
    Field atpField(gridWidth, gridHeight, regionConfig.getDiffusionCoefficient(), regionConfig.getExtracellularDecay(), dt);
    
    // Set ATP source at the center (simulate injursy)
    atpField.setSource(gridHeight / 2, gridWidth / 2, 1.0);
    
    // Initialize microglia agents
    std::vector<Microglia> microglia;
    microglia.emplace_back(50.0, 90.0, 0.05);
    microglia.emplace_back(55.0, 85.0, 0.05);
    
    // Initialize solvers
    RungeKuttaSolver rkSolver(dt);
    AdaptiveMeshSolver adaptiveSolver(dt);
    
    // Initialize visualization
    Visualization viz;
    
    // Main simulation loop
    for (double t = 0; t < simulationTime; t += dt) {
        adaptiveSolver.solve(atpField);
        
        for (auto &cell : microglia) {
            cell.senseAndReact(atpField);
            Vector2D gradient = atpField.getGradient(cell.getPosition());
            cell.move(gradient, dt);
            cell.update(dt);
        }
        
        viz.render(atpField, microglia);
    }
    
    std::cout << "Simulation completed." << std::endl;
    return 0;
}
