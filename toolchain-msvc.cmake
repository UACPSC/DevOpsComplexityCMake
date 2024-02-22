# toolchain-msvc.cmake

if(NOT MSVC)
    return()
endif()

add_compile_options(/Wall)
