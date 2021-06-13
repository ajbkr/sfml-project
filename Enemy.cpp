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

bool Enemy::check_if_hit(sf::Vector2i mouse_pos) {
  float enemy_min_x = enemy_sprite.getGlobalBounds().left;
  float enemy_max_x = enemy_min_x + enemy_sprite.getGlobalBounds().width;
  float enemy_min_y = enemy_sprite.getGlobalBounds().top;
  float enemy_max_y = enemy_min_y + enemy_sprite.getGlobalBounds().height;

  float mouse_x = mouse_pos.x;
  float mouse_y = mouse_pos.y;

  return mouse_x >= enemy_min_x && mouse_x <= enemy_max_x &&
    mouse_y >= enemy_min_y && mouse_y <= enemy_max_y;
}

bool Enemy::take_damage(int damage) {
  energy -= damage;
  attack_sound.play();
  return energy <= 0;
}
