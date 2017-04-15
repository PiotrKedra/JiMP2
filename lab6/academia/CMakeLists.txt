project(academia)

set(HEDEAR_FILES StudentRepository.h)
set(SOURCE_FILES StudentRepository.cpp)

add_library(libacademia STATIC ${SOURCE_FILES})
target_include_directories(libacademia PUBLIC .)

add_executable(academia ${SOURCE_FILES} main.cpp)

target_link_libraries(academia libacademia)