find_program(ALR_EXECUTABLE NAMES alr)
find_program(GPRBUILD_EXECUTABLE NAMES gprbuild)

if(ALR_EXECUTABLE)
    message(STATUS "Ada builder: Alire (${ALR_EXECUTABLE})")

    set(ADA_BUILD_COMMAND
        "${ALR_EXECUTABLE}" build
    )

elseif(GPRBUILD_EXECUTABLE)
    message(STATUS "Ada builder: GPRbuild (${GPRBUILD_EXECUTABLE})")

    set(ADA_BUILD_COMMAND
        "${GPRBUILD_EXECUTABLE}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/world_engine_planet.gpr"
        -p
    )

else()
    message(FATAL_ERROR
        "Neither Alire nor GPRbuild could be found. "
        "Install Alire or GPRbuild to build the Ada component."
    )
endif()

# Expected GPRbuild output.
set(ADA_ARCHIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/../../build/planet/lib/libWorld_Engine_Planet.a"
)

add_custom_command(
    OUTPUT "${ADA_ARCHIVE}"

    COMMAND ${ADA_BUILD_COMMAND}

    WORKING_DIRECTORY
        "${CMAKE_CURRENT_SOURCE_DIR}"

    DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/world_engine_planet.gpr"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/world_engine_planet.adb"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/world_engine_planet.ads"

    VERBATIM
)

add_custom_target(world_engine_ada_build
    DEPENDS "${ADA_ARCHIVE}"
)

add_library(world_engine_ada STATIC IMPORTED GLOBAL)

set_target_properties(world_engine_ada PROPERTIES
    IMPORTED_LOCATION "${ADA_ARCHIVE}"
)

add_dependencies(world_engine world_engine_ada_build)

target_link_libraries(world_engine PRIVATE
    world_engine_ada
)