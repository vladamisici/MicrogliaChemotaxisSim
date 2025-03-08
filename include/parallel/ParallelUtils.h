// Utilities for parallel computing (OpenMP/MPI wrappers)

#ifndef PARALLEL_UTILS_H
#define PARALLEL_UTILS_H

#ifdef _OPENMP
#include <omp.h>
#endif

namespace ParallelUtils {
    inline int getNumThreads() {
    #ifdef _OPENMP
        return omp_get_max_threads();
    #else
        return 1;
    #endif
    }
}

#endif // PARALLEL_UTILS_H
