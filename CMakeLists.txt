cmake_minimum_required (VERSION 2.8)

project (demons)
include_directories (src)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmaketools")
find_package(FreeImage)

add_executable(main 
	src/main.cpp
	src/gaussinterpolator.cpp
	src/lagrangeinterpolator.cpp
	src/linearinterpolator.cpp
	src/hdrimage.cpp)

include_directories("${FreeImage_INCLUDE_DIRS}")
target_link_libraries(main ${FreeImage_LIBRARIES})
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")