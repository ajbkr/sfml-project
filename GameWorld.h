// NOLINT(legal/copyright)
#ifndef GAMEWORLD_H_
#define GAMEWORLD_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameWorld {
  bool is_game_over;
  int damage;
  sf::Texture background_texture;
  sf::Sprite background;
  sf::Time time;

  bool load_background();

 public:
  GameWorld();

  bool perform_setup();
  bool run_game();
};

#endif  // GAMEWORLD_H_
