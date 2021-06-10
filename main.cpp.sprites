// Copyright 2021 Andrew J. Baker
#include <iostream>  // cerr, cout, endl

#include <SFML/Graphics.hpp>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

  sf::Texture enemyTexture;
  if (!enemyTexture.loadFromFile("assets/enemy.png")) {
    std::cerr << "Could not load enemy texture" << std::endl;
    return 1;
  }

  sf::Sprite enemySprite;
  enemySprite.setTexture(enemyTexture);
  enemySprite.setPosition(sf::Vector2f(100.0F, 100.0F));
  enemySprite.setScale(sf::Vector2f(1.0F, 1.5F));

  sf::Texture backgroundTexture;
  if (!backgroundTexture.loadFromFile("assets/background.png")) {
    std::cerr << "Could not load background texture" << std::endl;
    return 1;
  }

  sf::Sprite backgroundSprite;
  backgroundSprite.setTexture(backgroundTexture);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(backgroundSprite);
    window.draw(enemySprite);
    window.display();
  }

  return 0;
}
