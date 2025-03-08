#include "solvers/AdaptiveMeshSolver.h"
#include "fields/Field.h"

AdaptiveMeshSolver::AdaptiveMeshSolver(double dt) : dt(dt) {}

void AdaptiveMeshSolver::solve(Field &field) {
    // Placeholder: currently calls base update.
    // Extend with adaptive mesh refinement as needed.
    field.update();
}
