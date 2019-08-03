project(datastructures)

# All sources that also need to be tested in unit tests go into a static library
#add_library(hello_lib STATIC hello.cpp hello.h)
#target_include_directories(hello_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(LIB_INCLUDES
  # data structures include headers
  LinkedList.h
  Stack.h
  Queue.h
)

set(LIB_SOURCES
  # datastructrues class definitions
  LinkedList.cpp
  Stack.cpp
  Queue.cpp
)

# The main program
add_library(datastructures STATIC ${LIB_SOURCES} ${LIB_INCLUDES})
target_include_directories(datastructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(datastructures PRIVATE utils)