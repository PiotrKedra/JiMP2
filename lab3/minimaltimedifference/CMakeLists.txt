project(minimaltimedifference)

set(HEDEAR_FILES MinimalTimeDifference.h)
set(SOURCE_FILES MinimalTimeDifference.cpp)

add_library(libminimaltimedifference STATIC ${SOURCE_FILES})
target_include_directories(libminimaltimedifference PUBLIC .)

add_executable(minimaltimedifference ${SOURCE_FILES} main.cpp)

target_link_libraries(minimaltimedifference libminimaltimedifference)