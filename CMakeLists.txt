cmake_minimum_required(VERSION 3.7)


project(MathLibrary VERSION 1.0 DESCRIPTION "My C++ Math library" LANGUAGES CXX)
#Fix for windows builds
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

set( INC_FILES
	CorePhysics.hpp
    Transform.hpp
    MathFunctions.hpp
    World.hpp
)

set( SRC_FILES 
    Transform.cpp
    MathFunctions.cpp
    World.cpp
)
set (ALL_FILES ${INC_FILES} ${SRC_FILES})

add_library (MathLibrary STATIC ${ALL_FILES})

target_include_directories( MathLibrary
    PUBLIC ./    
)
