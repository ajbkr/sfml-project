// NOLINT(legal/copyright)
#include <iostream>  // cerr, endl

#include "Texts.h"

Texts::Texts() {
  end_game_won_text.setString("You won!");
  end_game_space_text.setString("Press SPACE to play again");
}

void Texts::set_up_text(sf::Text *text, sf::Vector2f position) {
  text->setFont(font);
  text->setCharacterSize(25);
  text->setFillColor(sf::Color::White);
  text->setStyle(sf::Text::Bold);
  text->setPosition(position);
}

bool Texts::perform_setup() {
  if (!font.loadFromFile("assets/ArialNarrow7-JB8E.ttf")) {
    std::cerr << "Could not load font file" << std::endl;
    return false;
  }

  set_up_text(&energy_text, sf::Vector2f(325.0F, 400.0F));
  set_up_text(&time_text, sf::Vector2f(325.0F, 450.0F));
  set_up_text(&end_game_won_text, sf::Vector2f(200.0F, 300.0F));
  set_up_text(&end_game_time_text, sf::Vector2f(200.0F, 350.0F));
  set_up_text(&end_game_space_text, sf::Vector2f(100.0F, 400.0F));

  return true;
}

void Texts::draw_in_game_text(sf::RenderWindow *window, sf::Time time,
 int energy) {
  energy_text.setString("Energy: " + std::to_string(energy));
  time_text.setString("Time: " + std::to_string(
    static_cast<int>(time.asSeconds())) + "s");
  window->draw(energy_text);
  window->draw(time_text);
}

void Texts::draw_end_game_text(sf::RenderWindow *window, sf::Time time) {
  end_game_time_text.setString("Time: " + std::to_string(
    static_cast<int>(time.asSeconds())) + "s");
  window->draw(end_game_won_text);
  window->draw(end_game_time_text);
  window->draw(end_game_space_text);
}
