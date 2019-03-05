project (Utils)

# Adding Utils Library

set(LIB_SOURCES
  src/DateTime.cpp
  src/Measure.cpp
  src/Random.cpp
  src/Random_test.cpp
  src/Time.cpp
  src/Time_test.cpp
)

set(LIB_INCLUDES
  include/Utils/CompilerVersion.h
  include/Utils/DateTime.h
  include/Utils/Map.h
  include/Utils/Measure.h
  include/Utils/Random.h
  include/Utils/Time.h
  include/Utils/Utils.h
)

add_library(utils STATIC ${LIB_SOURCES} ${LIB_INCLUDES})

# INTERFACE targets only have INTERFACE properties
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)