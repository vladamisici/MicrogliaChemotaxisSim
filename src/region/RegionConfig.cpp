#include "region/RegionConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>

RegionConfig::RegionConfig()
    : regionName("Default"), diffusionCoefficient(0.0001), extracellularDecay(0.01), ecmFactor(1.0) {}

void RegionConfig::loadConfig(const std::string &configFile) {
    std::ifstream file(configFile);
    if (!file) {
        std::cerr << "Error: Could not open config file: " << configFile << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#' || line.find('=') == std::string::npos)
            continue;
        std::istringstream iss(line);
        std::string key, eq, value;
        iss >> key >> eq >> value;
        if (key == "region_name") regionName = value;
        else if (key == "diffusion_coefficient") diffusionCoefficient = std::stod(value);
        else if (key == "extracellular_decay") extracellularDecay = std::stod(value);
        else if (key == "ecm_factor") ecmFactor = std::stod(value);
    }
}

std::string RegionConfig::getRegionName() const {
    return regionName;
}

double RegionConfig::getDiffusionCoefficient() const {
    return diffusionCoefficient;
}

double RegionConfig::getExtracellularDecay() const {
    return extracellularDecay;
}

double RegionConfig::getECMFactor() const {
    return ecmFactor;
}
