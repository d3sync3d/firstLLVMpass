cmake_minimum_required(VERSION 3.28)
project(FirstLLVMConsumer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LLVM_PATH "C:\\Program Files (x86)\\LLVM")

list(APPEND CMAKE_PREFIX_PATH ${LLVM_PATH})

find_package(LLVM REQUIRED CONFIG)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories("include")
file(GLOB_RECURSE HEADERS include/*.h)

add_executable(FirstLLVMConsumer ${SOURCES} ${HEADERS})

target_compile_features(FirstLLVMConsumer PRIVATE cxx_std_17)

target_link_libraries(FirstLLVMConsumer LLVMCore LLVMAnalysis LLVMTransformUtils LLVMPasses)