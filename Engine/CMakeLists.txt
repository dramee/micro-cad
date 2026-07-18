project(Engine)


find_package(SDL2 REQUIRED)


file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
)


add_library(
    Engine STATIC

    ${ENGINE_SOURCES}
)


target_include_directories(
    Engine

    PUBLIC

    include
)


target_link_libraries(
    Engine

    PUBLIC

    SDL2::SDL2
)