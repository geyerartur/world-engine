
target_sources(world_engine PRIVATE
    cosmos.f90
)

set_target_properties(world_engine PROPERTIES
    Fortran_MODULE_DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/modules"
)
