#include "Game.h"

void Game::run()
{
	while (m_running)
	{
		m_entities.update();

		if (!m_paused)
		{
			sEnemySpawner();
			sMovement();
			sCollision();
		}
		sUserInput();
		sRender();

		m_currentFrame++;//could be affected by pause

	}
}

void Game::setPaused(bool paused)
{
	m_paused = paused;
}

void Game::updateWindow()
{
	m_window.create(sf::VideoMode({ (unsigned int)m_windowSize.x, (unsigned int)m_windowSize.y }), "SimEngine", sf::Style::Default);
	m_window.setMouseCursorVisible(false);
	m_window.setFramerateLimit(m_frameLimit);
	sf::Image iconImage("assets/SFMLPracticeIcon.png");
	m_window.setIcon(iconImage);

}

void Game::sMovement()
{
	if (m_player->cInput->up)
	{
		m_player->cTransform->velocity.y -= 1.0f;
	}
}

void Game::sUserInput()
{
	while (const std::optional event = m_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			m_window.close();
			m_running = false;
		}

		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			switch (keyPressed->scancode)
			{
			case sf::Keyboard::Scancode::W:
				m_player->cInput->up = true;
				break;
			case sf::Keyboard::Scancode::S:
				m_player->cInput->down = true;
				break;
			case sf::Keyboard::Scancode::A:
				m_player->cInput->left = true;
				break;
			case sf::Keyboard::Scancode::D:
				m_player->cInput->right = true;
				break;
			case sf::Keyboard::Scancode::Escape:
				m_paused = !m_paused;
				break;
			}
		}
		if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
		{
			switch (keyReleased->scancode)
			{
			case sf::Keyboard::Scancode::W:
				m_player->cInput->up = false;
				break;
			case sf::Keyboard::Scancode::S:
				m_player->cInput->down = false;
				break;
			case sf::Keyboard::Scancode::A:
				m_player->cInput->left = false;
				break;
			case sf::Keyboard::Scancode::D:
				m_player->cInput->right = false;
				break;
			}
		}
		if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mouseClick->button == sf::Mouse::Button::Left)
			{
				m_player->cInput->primaryAction = true;
			}

		}
		if (const auto* mouseRelease = event->getIf<sf::Event::MouseButtonReleased>())
		{
			if (mouseRelease->button == sf::Mouse::Button::Left)
			{
				m_player->cInput->primaryAction = false;
			}

		}

		if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
		{
			m_player->cInput->mousePosition = Vec2((float)mouseMoved->position.x, (float)mouseMoved->position.y);
		}

		if (const auto* resized = event->getIf<sf::Event::Resized>())
		{
			m_windowSize = Vec2((float)resized->size.x, (float)resized->size.y);
			updateWindow();
		}


	}
	
}

void Game::sRender()
{
}

void Game::sEnemySpawner()
{
}

void Game::sCollision()
{
}

void Game::spawnPlayer()
{
}

void Game::spawnEnemy(SimpEntPtr entity)
{
}

void Game::spawnProjectile(SimpEntPtr entity)
{
}
