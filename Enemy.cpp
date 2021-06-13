// NOLINT(legal/copyright)
#include <iostream>  // cerr, endl

#include "Enemy.h"

Enemy::Enemy(int e) {
  energy = e;
}

bool Enemy::perform_setup() {
  if (!enemy_texture.loadFromFile("assets/enemy.png")) {
    std::cerr << "Could not load enemy image" << std::endl;
    return false;
  }

  enemy_sprite.setTexture(enemy_texture);
  enemy_sprite.setPosition(sf::Vector2f(112.5F, 200.0F));

  if (!attack_sound_buffer.loadFromFile("assets/damage.ogg")) {
    std::cerr << "Could not load enemy audio" << std::endl;
    return false;
  }
  attack_sound.setBuffer(attack_sound_buffer);

  return true;
}

void Enemy::draw(sf::RenderWindow *window) {
  window->draw(enemy_sprite);
}
