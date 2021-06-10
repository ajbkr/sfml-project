// Copyright 2021 Andrew J. Baker
#include <iostream>  // cerr, cout, endl

#include <SFML/Graphics.hpp>

#include "config.h"  // main_VERSION_MAJOR, main_VERSION_MINOR

int main() {
  std::cout << "Version " << main_VERSION_MAJOR << "." << main_VERSION_MINOR <<
   std::endl;

  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

  sf::Font font;
  if (!font.loadFromFile("assets/ArialNarrow7-JB8E.ttf")) {
    std::cerr << "Could not load font file" << std::endl;
    return 1;
  }

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(30);
  text.setFillColor(sf::Color::White);
  text.setStyle(sf::Text::Bold);
  text.setPosition(sf::Vector2f(100.0F, 100.0F));
  text.setString("Here is some text");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(text);
    window.display();
  }

  return 0;
}
