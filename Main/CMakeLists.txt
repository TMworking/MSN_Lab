file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(main ${srcs} ${hdrs} first.h KraskalMass.h KraskalRank.h)