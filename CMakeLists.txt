cmake_minimum_required(VERSION 3.20)
project(Geometry LANGUAGES CXX)

# pas de fichier .cpp juste du .hpp
add_library(geometry INTERFACE)

# chemin pour mes header files
target_include_directories(geometry INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# compilateur doit-etre C++ 20 and more
target_compile_features(geometry INTERFACE cxx_std_20)

if (MSVC)
  target_compile_options(geometry INTERFACE /W4 /permissive-)
else()
  target_compile_options(geometry INTERFACE -Wall -Wextra -Wpedantic)
endif()

#--- GOOGLE -------------------------
include(FetchContent)

if (MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)

set(BUILD_SHARED_LIBS OFF)  # build static library (MinGW-friendly)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
#--------------------------------------

# Active le système de tests intégré à CMake. 
# Permet d’utiliser la commande ctest pour lancer les tests après compilation.
enable_testing()

# Crée l'exécutable de tests
add_executable(vector_tests
    tests/vector_tests.cpp
)

# Lien avec GoogleTest et ta librairie
target_link_libraries(vector_tests
    PRIVATE
        geometry
        GTest::gtest_main
)

# Lier pthread sur MinGW
if(NOT MSVC)
    target_compile_options(vector_tests PRIVATE -pthread)
    target_link_libraries(vector_tests PRIVATE -static -pthread)
endif()


include(GoogleTest)
gtest_discover_tests(vector_tests)




