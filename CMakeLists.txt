# Build for Complexity program

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(Complexity)

# srccomplexity
add_executable(srccomplexity)
target_sources(srccomplexity PRIVATE srcComplexity.cpp srcMLXPathCount.cpp)
target_compile_features(srccomplexity PRIVATE cxx_std_17)

# libxml2
find_package(LibXml2 REQUIRED)
target_link_libraries(srccomplexity PRIVATE LibXml2::LibXml2)
