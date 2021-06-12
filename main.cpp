// Copyright 2021 Andrew J. Baker
#include <iostream>  // cout, endl

#include <SFML/Graphics.hpp>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

  sf::Clock clock;
  clock.restart();
  sf::Time time;

  while (window.isOpen()) {
    time = clock.getElapsedTime();
    float seconds = time.asSeconds();
    std::cout << seconds << std::endl;

    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.display();
  }

  return 0;
}
