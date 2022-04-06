cmake_minimum_required(VERSION 3.15)

project(test_leetcode)

enable_testing()

add_subdirectory(googletest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include)

include_directories("../src")

aux_source_directory("../src/common" common_SOURCES)
aux_source_directory("../src/datastructure" datastructure_SOURCES)
aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" test_SOURCES)

add_executable(${PROJECT_NAME}
        ${common_SOURCES}
        ${test_SOURCES}
        ${datastructure_SOURCES})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        gtest
        gtest_main  # 使用gtest带的main函数,如果检测到外部有main函数，则使用外部main函数,外部main函数要配置gtest初始化。
        gmock
        gmock_main  # 使用gmock带的main函数,如果检测到外部有main函数，则使用外部main函数,与gtest_main同时存在则自动配置。
        pthread)