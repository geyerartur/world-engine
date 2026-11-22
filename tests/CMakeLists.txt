add_executable(smoke_test
    smoke_test.c
)

target_link_libraries(smoke_test PRIVATE
    world_engine
)

target_include_directories(smoke_test PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

enable_testing()

add_test(
    NAME smoke_test
    COMMAND smoke_test
)