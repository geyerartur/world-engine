#include <stdlib.h>

#include "world_engine/world_engine.h"

struct we_universe {
    uint64_t seed;
};

we_result we_generate(
    const we_config *config,
    we_universe **out_universe
) {
    if (!config || !out_universe) {
        return WE_ERROR_INVALID_ARGUMENT;
    }

    *out_universe = NULL;

    we_universe *universe = calloc(1, sizeof(*universe));
    if (!universe) {
        return WE_ERROR_OUT_OF_MEMORY;
    }

    universe->seed = config->seed;
    *out_universe = universe;

    return WE_SUCCESS;
}

void we_universe_destroy(we_universe *universe) {
    free(universe);
}
