// Base class for all agents (for extensibility)

#ifndef AGENT_H
#define AGENT_H

#include "fields/Vector2D.h"

class Agent {
public:
    Agent(double x, double y);
    virtual ~Agent() = default;
    
    virtual void update(double dt) = 0; // Update state per time step
    virtual void move(const Vector2D &direction, double dt) = 0; // Move based on a direction

    Vector2D getPosition() const;
    
protected:
    Vector2D position;
};

#endif // AGENT_H
