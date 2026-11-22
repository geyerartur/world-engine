cmake_minimum_required(VERSION 4.4.1)

project(
    WorldEngine
    VERSION 0.0.1.0
    DESCRIPTION "A library dedicated to generating coherent galaxies and planetary systems."
    LANGUAGES C Fortran
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_Fortran_STANDARD 2018)
set(CMAKE_Fortran_STANDARD_REQUIRED ON)

add_library(world_engine SHARED)

target_sources(world_engine PRIVATE
    src/orchestrator/world_engine.c
)

add_subdirectory(src/cosmos)
add_subdirectory(src/planet)

target_include_directories(world_engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(world_engine PRIVATE
    WORLD_ENGINE_BUILD
)

set_target_properties(world_engine PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    OUTPUT_NAME world_engine
)

enable_testing()

add_executable(world_engine_smoke_test tests/smoke_test.c)
target_link_libraries(world_engine_smoke_test PRIVATE world_engine)

add_test(NAME world_engine_smoke_test COMMAND world_engine_smoke_test)