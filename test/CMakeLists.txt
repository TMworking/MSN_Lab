file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(test ${srcs} ${hdrs})
target_include_directories(test PUBLIC ../gtest)
target_link_libraries(test gtest)
include_directories(../Main)