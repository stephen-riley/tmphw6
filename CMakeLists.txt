cmake_minimum_required(VERSION 3.29)
project(hw6)

set(CMAKE_CXX_STANDARD 20)

add_executable(hw6 main.cpp
        INode.h
        Value.cpp
        Value.h
        Operator.cpp
        Operator.h
        NodeIterator.cpp
        NodeIterator.h)
