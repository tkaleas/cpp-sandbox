cmake_minimum_required(VERSION 3.5) # first version with add_compile_options()

#Project Name: Top Level Project
project(sandbox)

## Visual Studio Specific Options
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX-)
# None Visual Studio Options
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

#Third Party or Extra Libraries: add first
add_subdirectory(lib/catch)
add_subdirectory(lib/utils)

# extra projects
add_subdirectory(src)
add_subdirectory(test)

###
# Problem Solving Sub Directories
###

add_subdirectory(src/datastructures)
#add_subdirectory(directed_graphs)
#add_subdirectory(linked_lists)