cmake_minimum_required(VERSION 3.7)
project(Tarea1)

set(CMAKE_CXX_STANDARD 11)

#find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
#
#if(Boost_FOUND)
#    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
#    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
#    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
#    include_directories(${Boost_INCLUDE_DIRS})
#endif()
#
#add_executable(BoostTest main.cpp)
#
#if(Boost_FOUND)
#    target_link_libraries(BoostTest ${Boost_LIBRARIES})
#endif()

set(SOURCE_FILES main.cpp Point.h Vector.h Segment.h Polygon.h giftWrapping.h quickHull.h pointGenerator.h)
add_executable(Tarea1 ${SOURCE_FILES})