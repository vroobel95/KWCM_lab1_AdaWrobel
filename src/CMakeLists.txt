cmake_minimum_required (VERSION 2.8)
project (PierwszyProgram)
add_executable(Laborka main.cpp)

if (USE_TRIGONOMETRY_DEGREE)
include_directories ("${PROJECT_SOURCE_DIR}/Trygonometria")
add_subdirectory(Trygonometria)
target_link_libraries (Laborka Trygonometria)
endif (USE_TRIGONOMETRY_DEGREE)

option (USE_TRIGONOMETRY_DEGREE
"Czy argumentami funkcji trygonometrycznych maja byc stopnie" ON)

configure_file (
"${PROJECT_SOURCE_DIR}/LaborkaConfig.h.in"
"${PROJECT_BINARY_DIR}/LaborkaConfig.h"
)
include_directories("${PROJECT_BINARY_DIR}")

option (BUILD_TESTS
"Czy maja byc budowane testy" ON)

if (BUILD_TESTS)
enable_testing()

add_test (LaborkaPodstawowyTest Laborka)

add_test (LaborkaWynikSin45 Laborka 45)
set_tests_properties (LaborkaWynikSin45
PROPERTIES PASS_REGULAR_EXPRESSION "0[.,]70710")
 
add_test (Laborka3sek Laborka)
set_tests_properties (Laborka3sek
PROPERTIES TIMEOUT 3)
endif (BUILD_TESTS)