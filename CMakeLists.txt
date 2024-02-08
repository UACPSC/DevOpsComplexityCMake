# Build for Complexity program

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(Complexity)

# srccomplexity
add_executable(srccomplexity)
target_sources(srccomplexity PRIVATE srcComplexity.cpp)
target_compile_features(srccomplexity PRIVATE cxx_std_17)

# srcMLXPathCountTest
add_executable(srcMLXPathCountTest)
target_sources(srcMLXPathCountTest PRIVATE srcMLXPathCountTest.cpp)
target_compile_features(srcMLXPathCountTest PRIVATE cxx_std_17)

# libxml2
find_package(LibXml2 REQUIRED)
target_link_libraries(srccomplexity PRIVATE LibXml2::LibXml2)
target_link_libraries(srcMLXPathCountTest PRIVATE LibXml2::LibXml2)

# srcMLXPathCount library
add_library(srcMLXPathCount OBJECT srcMLXPathCount.cpp)
target_link_libraries(srcMLXPathCount PRIVATE LibXml2::LibXml2)
target_link_libraries(srccomplexity PRIVATE srcMLXPathCount)
target_link_libraries(srcMLXPathCountTest PRIVATE srcMLXPathCount)

# run
add_custom_target(run
    COMMENT "Complexity"
    COMMAND $<TARGET_FILE:srccomplexity> < ${CMAKE_CURRENT_SOURCE_DIR}/srcMLXPathCount.cpp.xml
    DEPENDS srccomplexity
    USES_TERMINAL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# install
install(PROGRAMS $<TARGET_FILE:srccomplexity> TYPE BIN)
