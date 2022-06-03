cmake_minimum_required(VERSION 3.0.0)
project(ED22-01-AVALOS-RIOS VERSION 0.1.0)

include(CTest)
enable_testing()
#Tengo que importar todos mis modulos que este utilizando
include_directories("src")
add_executable(ED22_01_AVALOS_RIOS src/logic/Nodo.cpp src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
