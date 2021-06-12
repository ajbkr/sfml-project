// Copyright 2021 Andrew J. Baker
#include <iostream>  // cout, endl

#include <SFML/Graphics.hpp>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

  sf::CircleShape shape(100.0F);
  shape.setFillColor(sf::Color::Green);

  int x = 0, y = 0;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        std::cout << "Mouse button pressed" << std::endl;
      } else if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
          std::cout << "Space bar pressed" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          if (x >= 10) {
            x -= 10;
          }
          shape.setPosition(x, y);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          if (x <= 290) {
            x += 10;
          }
          shape.setPosition(x, y);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          if (y >= 10) {
            y -= 10;
          }
          shape.setPosition(x, y);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          if (y <= 290) {
            y += 10;
          }
          shape.setPosition(x, y);
        }
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
