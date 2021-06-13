// NOLINT(legal/copyright)
#include <iostream>  // cerr, cout, endl

#include "GameWorld.h"

GameWorld::GameWorld(): enemy(100) {
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
  enemy = Enemy(100);
  texts = Texts();
  return load_background() && enemy.perform_setup() && texts.perform_setup();
}

bool GameWorld::run_game() {
  sf::RenderWindow window(sf::VideoMode(500, 500), "Point and Click Game");
  sf::Clock clock;

  while (window.isOpen()) {
    time = clock.getElapsedTime();

    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        return false;
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (enemy.check_if_hit(sf::Mouse::getPosition(window))) {
          enemy.take_damage(damage);
          std::cout << "Clicked on enemy" << std::endl;
        }
      }
    }

    window.clear();
    window.draw(background);
    enemy.draw(&window);
    texts.draw_in_game_text(&window, time, enemy.energy);
    // texts.draw_end_game_text(&window, time);
    window.display();
  }
  return false;
}
