project(arabicroman)

set(HEDEAR_FILES arabicroman.h)
set(SOURCE_FILES arabicroman.cpp)

add_library(libarabicroman STATIC ${SOURCE_FILES})
target_include_directories(libarabicroman PUBLIC .)

add_executable(arabicroman ${SOURCE_FILES} main.cpp)

target_link_libraries(arabicroman libarabicroman)