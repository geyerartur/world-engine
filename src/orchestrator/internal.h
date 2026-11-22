
#ifndef WE_INTERNAL_H
#define WE_INTERNAL_H

#include <stdint.h>

/* Fortran / Cosmos */
extern void cosmos_generate(
    int64_t seed,
    int32_t galaxy_count,
    int32_t *generated_count
);

/* Ada / Planet */
extern int32_t planet_generate(
    int64_t seed,
    int32_t galaxy_count
);

#endif
