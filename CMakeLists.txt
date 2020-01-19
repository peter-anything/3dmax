cmake_minimum_required (VERSION 3.14)

project(TestExamples)

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

aux_source_directory(./source DIR_SRCS)

include_directories(./include)

add_executable(Demo ${DIR_SRCS})