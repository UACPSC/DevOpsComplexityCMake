# Build for Complexity program

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(Complexity)

# srccomplexity
add_executable(srccomplexity)
target_sources(srccomplexity PRIVATE srcComplexity.cpp)
target_compile_features(srccomplexity PRIVATE cxx_std_17)
target_compile_options(srccomplexity PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall>
)

# srcMLXPathCountTest
add_executable(srcMLXPathCountTest)
target_sources(srcMLXPathCountTest PRIVATE srcMLXPathCountTest.cpp)
target_compile_features(srcMLXPathCountTest PRIVATE cxx_std_17)

# libxml2
find_package(LibXml2 REQUIRED)
target_link_libraries(srccomplexity PRIVATE LibXml2::LibXml2)
target_link_libraries(srcMLXPathCountTest PRIVATE LibXml2::LibXml2)

# srcMLXPathCount library
add_library(srcMLXPathCount SHARED srcMLXPathCount.cpp)
target_compile_features(srcMLXPathCount PRIVATE cxx_std_17)
target_link_libraries(srcMLXPathCount PRIVATE LibXml2::LibXml2)
target_link_libraries(srccomplexity PRIVATE srcMLXPathCount)
target_link_libraries(srcMLXPathCountTest PRIVATE srcMLXPathCount)

# srcMLXPathCount static library
add_library(srcMLXPathCount_static STATIC srcMLXPathCount.cpp)
target_compile_features(srcMLXPathCount_static PRIVATE cxx_std_17)
target_link_libraries(srcMLXPathCount_static PRIVATE LibXml2::LibXml2)

# run
add_custom_target(run
    COMMENT "Complexity"
    COMMAND $<TARGET_FILE:srccomplexity> < ${CMAKE_CURRENT_SOURCE_DIR}/srcMLXPathCount.cpp.xml
    DEPENDS srccomplexity
    USES_TERMINAL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# install
install(TARGETS srccomplexity)
install(TARGETS srcMLXPathCount)

# testing
include(CTest)

add_test(NAME testComplexity1
         COMMAND ${CMAKE_SOURCE_DIR}/testsuite/testComplexity1.sh
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(NAME testComplexity2
         COMMAND ${CMAKE_SOURCE_DIR}/testsuite/testComplexity2.sh
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(CPACK_PACKAGE_NAME "complexity")
set(CPACK_PACKAGE_CONTACT "Me")
set(CPACK_STRIP_FILES ON)

# Leave after all cpack configuration
include(CPack)
