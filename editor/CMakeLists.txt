add_executable(editor WIN32
    src/main.cpp
)

target_link_libraries(editor PRIVATE engine)