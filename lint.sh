#!/usr/bin/env bash
#cppcheck --language=c++ --quiet --std=c++11 *.cpp *.h && cpplint --exclude=templateCode.cpp --filter=-build/include_subdir --quiet *.cpp *.h
cppcheck --language=c++ --quiet --std=c++11 *.cpp && cpplint --exclude=templateCode.cpp --filter=-build/include_subdir --quiet *.cpp
