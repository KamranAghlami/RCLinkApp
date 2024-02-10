cmake_minimum_required(VERSION 3.20)

project(RCLinkApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.h" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

include(FetchContent)
FetchContent_Declare(
  libtlvcpp
  GIT_REPOSITORY https://github.com/KamranAghlami/libtlvcpp.git
  GIT_TAG origin/main
)
FetchContent_MakeAvailable(libtlvcpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tlvcpp)
