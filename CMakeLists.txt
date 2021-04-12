cmake_minimum_required(VERSION 3.5)

project(practice-gtest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)


add_executable(sample1 src/sample1.cpp)
target_link_libraries(sample1 gtest)
# add the binary tree to the search path for include files
target_include_directories(sample1 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            googletest/include)

add_executable(sample2 src/sample2.cpp)
target_link_libraries(sample2 gtest)
# add the binary tree to the search path for include files
target_include_directories(sample2 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            googletest/include)

add_executable(sample3 src/sample3.cpp)
target_link_libraries(sample3 gtest)
# add the binary tree to the search path for include files
target_include_directories(sample3 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            googletest/include)

add_executable(sample4 src/sample4.cpp)
target_link_libraries(sample4 gtest gmock)
# add the binary tree to the search path for include files
target_include_directories(sample4 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            googletest/include
                            googlemock/include)

add_executable(sample5 src/sample5.cpp)
target_link_libraries(sample5 gtest gmock)
# add the binary tree to the search path for include files
target_include_directories(sample5 PUBLIC 
                            "${PROJECT_BINARY_DIR}"
                            googletest/include
                            googlemock/include)