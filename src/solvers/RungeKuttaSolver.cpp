// High-order time integration method implementation

#include "solvers/RungeKuttaSolver.h"
#include "fields/Field.h"

RungeKuttaSolver::RungeKuttaSolver(double dt) : dt(dt) {}

void RungeKuttaSolver::solve(Field &field) {
    // For now, a placeholder using the Field update.
    field.update();
}
