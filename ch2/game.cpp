#include "game.h"

// 800, 600
Game::Game() : m_window("Cooler mushroom!", sf::Vector2u(1920,1080)) {
  // Setting up class members.
  m_mushroomTexture.loadFromFile("Mushroom.png");
  m_mushroom.setTexture(m_mushroomTexture);
  m_increment = sf::Vector2i(1000, 1000);
}

Game::~Game() {}

void Game::Update() {
  m_window.Update();
  MoveMushroom();
}

void Game::MoveMushroom() {
  sf::Vector2u l_windSize = m_window.GetWindowSize();
  sf::Vector2u l_textSize = m_mushroomTexture.getSize();

  if((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x
      && m_increment.x > 0) ||
     (m_mushroom.getPosition().x < 0 && m_increment.x < 0)) {
    // Reverse the direction on the X axis
    m_increment.x = -m_increment.x;
  }

  if((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y
      && m_increment.y > 0) ||
     (m_mushroom.getPosition().y < 0 && m_increment.y < 0)) {
    // Reverse the direction on the Y ayis
    m_increment.y = -m_increment.y;
  }

  float fElapsed = m_elapsed.asSeconds();
  
  m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x * fElapsed),
			 m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}


void Game::Render() {
  m_window.BeginDraw(); // Clear
  m_window.Draw(m_mushroom);
  m_window.EndDraw(); // Display
}

Window* Game::GetWindow() {
  return &m_window;
}

void Game::HandleInput() {}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
