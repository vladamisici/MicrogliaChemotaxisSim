#include "intracellular/Ectonucleotidase.h"
#include <cmath>

Ectonucleotidase::Ectonucleotidase(double conversionRate) : conversionRate(conversionRate) {}

double Ectonucleotidase::convert(double atpConcentration, double dt) {
    // First-order conversion: fraction converted in dt
    return atpConcentration * (1 - std::exp(-conversionRate * dt));
}
