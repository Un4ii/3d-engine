cmake_minimum_required(VERSION 3.25)

project("3D Engine"
    LANGUAGES CXX
    VERSION 0.1.0
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/EHs-c- /W4 /permissive-)
    add_compile_definitions(_HAS_EXCEPTIONS=0)
endif()

add_subdirectory(engine)
add_subdirectory(editor)