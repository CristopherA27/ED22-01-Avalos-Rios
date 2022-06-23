cmake_minimum_required(VERSION 3.0.0)
project(ED22-01-AVALOS-RIOS VERSION 0.1.0)

include(CTest)
enable_testing()
find_package( OpenCV REQUIRED)
#Tengo que importar todos mis modulos que este utilizando
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(ED22-01-Avalos-Rios Detector.cpp Nodo.cpp Persona.cpp Linked.cpp Nodo.cpp main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
