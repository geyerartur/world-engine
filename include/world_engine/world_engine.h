
#ifndef WORLD_ENGINE_H
#define WORLD_ENGINE_H

#include <stdint.h>

#ifdef _WIN32
    #ifdef WORLD_ENGINE_BUILD
        #define WE_API __declspec(dllexport)
    #else
        #define WE_API __declspec(dllimport)
    #endif
#else
    #define WE_API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    WE_SUCCESS = 0,
    WE_ERROR_INVALID_ARGUMENT = 1,
    WE_ERROR_GENERATION_FAILED = 2,
    WE_ERROR_OUT_OF_MEMORY = 3,
    WE_ERROR_INTERNAL = 4
} we_result;

typedef struct {
    uint64_t seed;
    uint32_t galaxy_count;
} we_config;

/* Opaque universe handle. */
typedef struct we_universe we_universe;

/* Public API */
WE_API we_result we_generate(
    const we_config *config,
    we_universe **out_universe
);

WE_API void we_universe_destroy(
    we_universe *universe
);

#ifdef __cplusplus
}
#endif

#endif
