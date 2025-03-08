#ifndef REGION_CONFIG_H
#define REGION_CONFIG_H

#include <string>

class RegionConfig {
public:
    RegionConfig();
    ~RegionConfig() = default;
    
    void loadConfig(const std::string &configFile);

    std::string getRegionName() const;
    double getDiffusionCoefficient() const;
    double getExtracellularDecay() const;
    double getECMFactor() const;

private:
    std::string regionName;
    double diffusionCoefficient;
    double extracellularDecay;
    double ecmFactor;
};

#endif // REGION_CONFIG_H
