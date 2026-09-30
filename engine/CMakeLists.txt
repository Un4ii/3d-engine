add_library(engine STATIC
    src/window.cpp
)

target_include_directories(engine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # $<INSTALL_INTERFACE:include>
)

# --- Libraries
find_package(Vulkan REQUIRED)

target_link_libraries(engine
    PRIVATE
        Vulkan::Vulkan
)

# --- Install
# install(TARGETS engine
#     EXPORT engineTargets
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
#     RUNTIME DESTINATION bin
# )
# install(DIRECTORY include/ DESTINATION include)
# install(EXPORT engineTargets
#     FILE engineConfig.cmake
#     NAMESPACE prefix::
#     DESTINATION lib/cmake/engine
# )