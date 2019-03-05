project(sandbox_tests)

# The test program
add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE catch)