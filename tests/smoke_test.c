#include <stdio.h>

#include "world_engine/world_engine.h"

int main(void)
{
    we_universe *universe = NULL;

    if (we_generate(NULL, &universe) != WE_ERROR_INVALID_ARGUMENT) {
        fputs("Smoke test failed: NULL config was accepted.\n", stderr);
        return 1;
    }

    const we_config config = {
        .seed = 123456789,
        .galaxy_count = 1
    };

    if (we_generate(&config, &universe) != WE_SUCCESS) {
        fputs("Smoke test failed: universe generation failed.\n", stderr);
        return 1;
    }

    if (universe == NULL) {
        fputs("Smoke test failed: universe handle is NULL.\n", stderr);
        return 1;
    }

    we_universe_destroy(universe);

    puts("Smoke test passed.");
    return 0;
}
