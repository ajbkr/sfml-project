// NOLINT(legal/copyright)
#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Enemy {
  sf::Texture enemy_texture;
  sf::Sprite enemy_sprite;
  sf::SoundBuffer attack_sound_buffer;
  sf::Sound attack_sound;

 public:
  int energy;

  explicit Enemy(int);

  bool perform_setup();
  bool check_if_hit(sf::Vector2i);
  bool take_damage(int);
  void draw(sf::RenderWindow *);
};

#endif  // ENEMY_H_
