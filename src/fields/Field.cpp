// Implements the reaction-diffusion solver for ATP

#include "fields/Field.h"
#include <cmath>
#include <algorithm>

Field::Field(int width, int height, double diffusion, double decay, double dt)
    : width(width), height(height), diffusion(diffusion), decay(decay), dt(dt) {
    grid.resize(height, std::vector<double>(width, 0.0));
    newGrid = grid;
}

void Field::update() {
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < width - 1; ++j) {
            double laplacian = grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - 4 * grid[i][j];
            newGrid[i][j] = grid[i][j] + dt * (diffusion * laplacian - decay * grid[i][j]);
        }
    }
    grid = newGrid;
    applyBoundaryConditions();
}

void Field::applyBoundaryConditions() {
    for (int i = 0; i < height; ++i) {
        grid[i][0] = grid[i][1];
        grid[i][width-1] = grid[i][width-2];
    }
    for (int j = 0; j < width; ++j) {
        grid[0][j] = grid[1][j];
        grid[height-1][j] = grid[height-2][j];
    }
}

void Field::setSource(int i, int j, double value) {
    if (i >= 0 && i < height && j >= 0 && j < width)
        grid[i][j] = value;
}

double Field::getValue(const Vector2D &pos) const {
    int i = static_cast<int>(pos.y);
    int j = static_cast<int>(pos.x);
    if (i < 0 || i >= height-1 || j < 0 || j >= width-1) return 0.0;
    double dx = pos.x - j;
    double dy = pos.y - i;
    double v1 = grid[i][j];
    double v2 = grid[i][j+1];
    double v3 = grid[i+1][j];
    double v4 = grid[i+1][j+1];
    return (1-dx)*(1-dy)*v1 + dx*(1-dy)*v2 + (1-dx)*dy*v3 + dx*dy*v4;
}

Vector2D Field::getGradient(const Vector2D &pos) const {
    int i = static_cast<int>(pos.y);
    int j = static_cast<int>(pos.x);
    if (i <= 0 || i >= height-1 || j <= 0 || j >= width-1)
        return Vector2D(0, 0);
    double dfdx = (grid[i][j+1] - grid[i][j-1]) / 2.0;
    double dfdy = (grid[i+1][j] - grid[i-1][j]) / 2.0;
    return Vector2D(dfdx, dfdy);
}
