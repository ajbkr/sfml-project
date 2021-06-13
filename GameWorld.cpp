// NOLINT(legal/copyright)
#include <iostream>  // cerr, endl

#include "GameWorld.h"

GameWorld::GameWorld() {
  damage = 10;
}

bool GameWorld::load_background() {
  if (!background_texture.loadFromFile("assets/background.png")) {
    std::cerr << "Could not load background image" << std::endl;
    return false;
  }

  background.setTexture(background_texture);
  background.scale(sf::Vector2f(0.8F, 1.1F));
  return true;
}

bool GameWorld::perform_setup() {
  is_game_over = false;
  return load_background();
}

bool GameWorld::run_game() {
  sf::RenderWindow window(sf::VideoMode(500, 500), "Point and Click Game");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        return false;
      }
    }

    window.clear();
    window.draw(background);
    window.display();
  }
  return false;
}
