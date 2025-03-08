#ifndef ECTONUCLEOTIDASE_H
#define ECTONUCLEOTIDASE_H

class Ectonucleotidase {
public:
    Ectonucleotidase(double conversionRate);
    ~Ectonucleotidase() = default;
    
    // Convert ATP to adenosine over a time step
    double convert(double atpConcentration, double dt);

private:
    double conversionRate;
};

#endif // ECTONUCLEOTIDASE_H
