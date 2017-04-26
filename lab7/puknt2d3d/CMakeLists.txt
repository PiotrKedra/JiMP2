project(punkt2d3d)

set(HEDEAR_FILES punkt.h)
set(SOURCE_FILES punkt.cpp)

add_library(libpunkt2d3d STATIC ${SOURCE_FILES})
target_include_directories(libpunkt2d3d PUBLIC .)

add_executable(punkt2d3d ${SOURCE_FILES} main.cpp)

target_link_libraries(punkt2d3d libpunkt2d3d)