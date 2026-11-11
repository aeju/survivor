#include "core/World.h"

void World::update(const InputState& input, float dt) {
    player_.update(input, dt);
}
