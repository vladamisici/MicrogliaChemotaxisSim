#ifndef ADAPTIVE_MESH_SOLVER_H
#define ADAPTIVE_MESH_SOLVER_H

#include "PDESolver.h"

class AdaptiveMeshSolver : public PDESolver {
public:
    AdaptiveMeshSolver(double dt);
    ~AdaptiveMeshSolver() = default;
    
    // Solve the field PDE using adaptive mesh refinement
    void solve(Field &field) override;

private:
    double dt;
    // Additional members for adaptive mesh control can be added here
};

#endif // ADAPTIVE_MESH_SOLVER_H
