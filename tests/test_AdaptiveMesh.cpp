#include "fields/Field.h"
#include "solvers/AdaptiveMeshSolver.h"
#include <cassert>
#include <iostream>

int main() {
    Field testField(10, 10, 0.1, 0.01, 0.001);
    AdaptiveMeshSolver solver(0.001);
    solver.solve(testField);
    std::cout << "Adaptive mesh solver test completed." << std::endl;
    return 0;
}
