#include "application.hpp"

namespace runner
{
	void Application::run()
	{
		const sf::VideoMode mode{ 1280, 720 };
		const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
		m_window.create(mode, flags);

		if (!m_window.isOpen() || !enter()) {
			return;
		}

		m_window.setKeyRepeatEnabled(false);

		while (m_window.isOpen()) {
			sf::Event event;

			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::KeyPressed) {
					on_key_pressed(event.key.code);
				}
				else if (event.type == sf::Event::Closed) {
					m_window.close();
				}
			}

			if (!Update()) {
				m_window.close();
			}

			Render();
		}

		exit();
	}

	bool Application::enter()
	{
		m_textManager.LoadFontFile("assets/fonts.ttf");
		menuText = m_textManager.SetText("SIMPLE DINO RUNNER", 120, sf::Color::Black, 20, 200);
		startText = m_textManager.SetText("Press S to start", 60, sf::Color::Black, 350, 350);
		loseText = m_textManager.SetText("press r to return to home page", 30, sf::Color::Black, 20, 450);
		retryText = m_textManager.SetText("press s to return to retry", 30, sf::Color::Black, 20, 500);
		return true;
	}

	void Application::exit() noexcept
	{
	}

	void Application::CheckCollision()
	{
		int quantity = m_ground.GetBarrierQuantity();

		for (int i = 0; i < quantity; i++) {
			sf::FloatRect barrierRect = m_ground.GetBarrier(i);

			if (barrierRect.left != 1280.0f) {
				bool collided = Collision::Collide(barrierRect, barrierRect, m_player.GetRect());
				if (collided) {
					m_state = GamesState::lose;
					GameOver();
				}
			}
		}
	}

	bool Application::Update()
	{
		m_deltatime = m_clock.restart().asSeconds();
		m_window.setTitle("score:" + std::to_string(m_score));

		if (m_state == GamesState::running){
			m_layer.UpdateEntities(m_deltatime);
			m_ground.Update(m_deltatime);
			m_player.Update(m_deltatime);
			CheckCollision();
			m_score += static_cast<int>(10000 * m_deltatime);
			currentScoreText = m_textManager.SetText("score:" + std::to_string(m_score), 30, sf::Color::White, 0, 0);
		}
		return m_running;
	}

	void Application::GameOver()
	{
		if (m_state == GamesState::lose){
			scoreText = m_textManager.SetText("score:" + std::to_string(m_score), 60, sf::Color::Black, 20, 300);
			if (m_score > m_high_score){
				m_high_score = m_score;
			}
			highScoreText = m_textManager.SetText("high score:" + std::to_string(m_high_score), 60, sf::Color::Black, 20, 200);
		}
	}

	void Application::Render()
	{
		m_batch.Clear();
		m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });

		switch (m_state) {
		case GamesState::menu:
			m_window.draw(menuText);
			m_window.draw(startText);
			break;

		case GamesState::running:
			m_layer.RenderEntities(m_batch);
			m_ground.Render(m_batch);
			m_batch.present(m_window);
			m_player.Render(m_window);
			m_window.draw(currentScoreText);
			break;

		case GamesState::lose:
			m_ground.Clear();
			m_layer.ClearEntities();
			m_window.draw(highScoreText);
			m_window.draw(scoreText);
			m_window.draw(retryText);
			m_window.draw(loseText);
			break;
		}
		m_window.display();
	}

	void Application::on_key_pressed(const sf::Keyboard::Key key)
	{
		if (key == sf::Keyboard::Key::Escape) {
			m_running = false;
		}

		if (key == sf::Keyboard::Key::Space) {
			m_player.Jump();
		}

		if (key == sf::Keyboard::Key::R) {
			if (m_state == GamesState::lose) {
				m_state = GamesState::menu;
			}
		}

		if (key == sf::Keyboard::Key::S) {
			if (m_state != GamesState::running) {
				m_state = GamesState::running;
				m_score = 0;
				m_ground = Ground();
				m_layer = Layer();
				//m_layer = std::make_unique<Layer>();
			}
		}
	}
} // !runner
