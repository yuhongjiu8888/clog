cmake_minimum_required(VERSION 3.10)

project(main CXX C) # 这里可以不写CXX和C，但不能只写一个，否则只会编译指定语言
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  #设置c++的编译选项
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")  #设置c的编译选项

add_definitions(-DLOG_USE_COLOR)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

FILE(GLOB src ${PROJECT_SOURCE_DIR}/*.c)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB samples ${PROJECT_SOURCE_DIR}/*.cpp)

ADD_EXECUTABLE(test_log   ${src} ${samples})
TARGET_LINK_LIBRARIES(test_log )

INSTALL(TARGETS test_log DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)