// Interface for PDE solvers (finite difference, etc.)

#ifndef PDESOLVER_H
#define PDESOLVER_H

#include "fields/Field.h"

class PDESolver {
public:
    virtual ~PDESolver() = default;
    virtual void solve(Field &field) = 0;
};

#endif // PDESOLVER_H
