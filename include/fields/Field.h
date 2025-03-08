// Class for ATP concentration field (reaction-diffusion)

#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Vector2D.h"

class Field {
public:
    Field(int width, int height, double diffusion, double decay, double dt);
    virtual ~Field() = default;

    // Update the field using a reaction–diffusion method
    virtual void update();

    // Set a source value at a specific grid location (i, j)
    void setSource(int i, int j, double value);

    // Get interpolated field value at a continuous position
    double getValue(const Vector2D &pos) const;

    // Compute gradient at a given position (using central differences)
    Vector2D getGradient(const Vector2D &pos) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    int width, height;
    double diffusion;
    double decay;
    double dt;
    std::vector<std::vector<double>> grid;
    std::vector<std::vector<double>> newGrid;

    void applyBoundaryConditions();
};

#endif // FIELD_H
