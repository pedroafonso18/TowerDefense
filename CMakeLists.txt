cmake_minimum_required(VERSION 3.31)
project(
  TowerDefense
  VERSION 1.0
  LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)

FetchContent_MakeAvailable(raylib)

add_executable(
  TowerDefense
  src/main.cpp
  src/Player.cpp
  src/Crate.cpp
  src/Hole.cpp
  src/CrateSpawner.cpp
  include/Constants.h
  include/Player.h
  include/Crate.h
  include/Hole.h
  include/CrateSpawner.h
  ThirdParty/timer.h
)

target_link_libraries(TowerDefense PRIVATE raylib)