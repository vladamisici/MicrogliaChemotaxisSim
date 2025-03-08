// Base agent implementations

#include "agents/Agent.h"

Agent::Agent(double x, double y) : position(x, y) {}

Vector2D Agent::getPosition() const {
    return position;
}
