#include "fields/AdenosineField.h"

AdenosineField::AdenosineField(int width, int height, double diffusion, double decay, double dt)
    : Field(width, height, diffusion, decay, dt) {}

void AdenosineField::update() {
    // Custom adenosine dynamics can be implemented here; for now, use base update
    Field::update();
}
