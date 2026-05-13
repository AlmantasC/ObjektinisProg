cmake_minimum_required(VERSION 3.10)
project(ObjektinisProg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

foreach(CONTAINER vector list deque)
    add_executable(${CONTAINER}
        ${CONTAINER}/main.cpp
        ${CONTAINER}/mylib.cpp
    )
    target_include_directories(${CONTAINER} PRIVATE ${CONTAINER})
endforeach()