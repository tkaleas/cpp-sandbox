project(sandbox_tests)

# The test program

set(EXE_SOURCES
  # main base tests
  testmain.cpp

  #datastructures testing
  datastructures_test.cpp
)

# The main test program
add_executable(tests testmain.cpp ${EXE_SOURCES})
target_link_libraries(tests PRIVATE catch)
target_link_libraries(tests PRIVATE datastructures)