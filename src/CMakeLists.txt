### include own stuff
file(GLOB_RECURSE _OWN_SRCS  "states/*.cpp" "input/*.cpp" "output/*.cpp" "infrastructure/*.cpp")


### Library files
include_directories(timer/)
set(_TIMER_LIB
        ${CMAKE_CURRENT_SOURCE_DIR}/Timer/Timer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Timer/Event.cpp)


### add all sources to project
set(${PROJECT_NAME}_SRCS ${${PROJECT_NAME}_SRCS} ${_TIMER_LIB} ${_OWN_SRCS} PARENT_SCOPE)