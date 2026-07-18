cmake_minimum_required(VERSION 3.20)

project(GraphicsEngine)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# -----------------------------------
# Clang tools
# -----------------------------------

option(ENABLE_CLANG_TIDY 
       "Enable clang-tidy checks"
       ON)


option(ENABLE_CLANG_FORMAT
       "Enable clang-format target"
       ON)



# clang-tidy
if(ENABLE_CLANG_TIDY)

    find_program(
        CLANG_TIDY
        clang-tidy
    )

    if(CLANG_TIDY)

        message(STATUS "clang-tidy found: ${CLANG_TIDY}")

        set(
            CMAKE_CXX_CLANG_TIDY
            ${CLANG_TIDY}
        )

    else()

        message(WARNING
            "clang-tidy not found"
        )

    endif()

endif()



# clang-format
if(ENABLE_CLANG_FORMAT)

    find_program(
        CLANG_FORMAT
        clang-format
    )


    if(CLANG_FORMAT)

        message(STATUS 
            "clang-format found: ${CLANG_FORMAT}"
        )


        file(
            GLOB_RECURSE
            ALL_SOURCE_FILES

            ${PROJECT_SOURCE_DIR}/Engine/*.cpp
            ${PROJECT_SOURCE_DIR}/Engine/*.h
            ${PROJECT_SOURCE_DIR}/Sandbox/*.cpp
        )


        add_custom_target(
            format

            COMMAND
            ${CLANG_FORMAT}
            -i
            ${ALL_SOURCE_FILES}

            COMMENT
            "Running clang-format"
        )


    else()

        message(WARNING
            "clang-format not found"
        )

    endif()

endif()



add_subdirectory(Engine)

add_subdirectory(Sandbox)