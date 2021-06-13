// Copyright 2021 Andrew J. Baker
#include <iostream>  // cout, endl

#include "GameWorld.h"

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  GameWorld world = GameWorld();
  while (true) {
    if (!world.perform_setup()) {
      return 1;
    }
    if (!world.run_game()) {
      return 0;
    }
  }

  return 0;
}
