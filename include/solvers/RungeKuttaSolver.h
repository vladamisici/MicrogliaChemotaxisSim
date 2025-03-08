// Implementation of high-order time integration for PDEs

#ifndef RUNGE_KUTTA_SOLVER_H
#define RUNGE_KUTTA_SOLVER_H

#include "PDESolver.h"

class RungeKuttaSolver : public PDESolver {
public:
    RungeKuttaSolver(double dt);
    ~RungeKuttaSolver() = default;
    
    // Solve the field PDE using Runge–Kutta integration
    void solve(Field &field) override;

private:
    double dt;
};

#endif // RUNGE_KUTTA_SOLVER_H
