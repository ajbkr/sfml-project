// Copyright 2021 Andrew J. Baker
#include <iostream>

#include <SFML/Graphics.hpp>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

  sf::CircleShape shape(100.0F);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
