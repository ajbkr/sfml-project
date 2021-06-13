// NOLINT(legal/copyright)
#ifndef TEXTS_H_
#define TEXTS_H_

#include <SFML/Graphics.hpp>

class Texts {
  sf::Font font;

  void set_up_text(sf::Text *, sf::Vector2f);

 public:
  sf::Text energy_text;
  sf::Text time_text;
  sf::Text end_game_won_text;
  sf::Text end_game_time_text;
  sf::Text end_game_space_text;

  Texts();

  bool perform_setup();
  void draw_in_game_text(sf::RenderWindow *, sf::Time, int);
  void draw_end_game_text(sf::RenderWindow *, sf::Time);
};

#endif  // TEXTS_H_
