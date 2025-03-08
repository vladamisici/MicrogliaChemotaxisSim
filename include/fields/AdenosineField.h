#ifndef ADENOSINEFIELD_H
#define ADENOSINEFIELD_H

#include "Field.h"

class AdenosineField : public Field {
public:
    AdenosineField(int width, int height, double diffusion, double decay, double dt);
    ~AdenosineField() = default;

    // Optionally override update() for custom adenosine dynamics
    void update() override;
};

#endif // ADENOSINEFIELD_H
