#pragma once
#include <SFML/Graphics.hpp>
#include "window.h"

class Game{
 public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  Window* GetWindow();
  sf::Time GetElapsed();
  void RestartClock();
  void ChangeFPS();

 private:
  void MoveMushroom();
  Window m_window;
  sf::Texture m_mushroomTexture;
  sf::Sprite m_mushroom;
  sf::Vector2i m_increment;
  sf::Clock m_clock;
  sf::Time m_elapsed;
  float m_sumElapsed;
  int m_fpsList[3];
  int m_currentFps;
};
