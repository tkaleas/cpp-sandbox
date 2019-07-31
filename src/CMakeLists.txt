project(hello_prog)

# All sources that also need to be tested in unit tests go into a static library
#add_library(hello_lib STATIC hello.cpp hello.h)
#target_include_directories(hello_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(EXE_INCLUDES
  exercises/exercises.h
  # copied from C++ Primer Source Code
  exercises/Sales_item.h
  # custom classes written for C++ pxrimer code
  exercises/Sales_data.h
  exercises/Person.h
  exercises/Screen.h
  exercises/Blob.h
  exercises/TextQuery.h
  exercises/Quote.h
)

set(EXE_SOURCES
  # extra exercise class definitions
  exercises/Blob.cpp
)

# The main program
add_executable(prog Main.cpp ${EXE_SOURCES} ${EXE_INCLUDES})
target_include_directories(prog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/exercises)
#target_link_libraries(prog PRIVATE catch)
target_link_libraries(prog PRIVATE utils)
target_link_libraries(prog PRIVATE datastructures)

# Input/Output Debugging with File I/O
if (MSVC)
  set_target_properties( prog PROPERTIES 
                         #VS_DEBUGGER_COMMAND_ARGUMENTS "<test_books.tt >output.txt")
                         VS_DEBUGGER_COMMAND_ARGUMENTS "<test_books.txt")
endif()