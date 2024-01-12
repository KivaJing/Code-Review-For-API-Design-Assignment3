#include "application.hpp"

namespace runner
{
	static const std::string kPlayerFrame1ID = "player1";
	static const std::string kPlayerFrame2ID = "player2";

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
		m_assetManager.LoadTexture(kPlayerFrame1ID, "assets/playerFrame1.png");
		m_assetManager.LoadTexture(kPlayerFrame2ID, "assets/playerFrame2.png");
		m_assetManager.LoadFontFile("assets/fonts.ttf");

		menuText = m_assetManager.SetText("SIMPLE DINO RUNNER", 120, sf::Color::Black, 20, 200);
		startText = m_assetManager.SetText("Press S to start", 60, sf::Color::Black, 350, 350);
		loseText = m_assetManager.SetText("press r to return to home page", 30, sf::Color::Black, 20, 450);
		retryText = m_assetManager.SetText("press s to return to retry", 30, sf::Color::Black, 20, 500);

		Restart();
		return true;
	}

	void Application::Restart()
	{
		m_score = 0;
		m_layer.Setup({ 20,120,50,150,150, false });
		m_closerLayer.Setup({ 50,250,100,300,250, true });
		m_ground.Setup();
		m_player.Setup(m_assetManager.GetTexture(kPlayerFrame1ID), m_assetManager.GetTexture(kPlayerFrame2ID));
	}

	void Application::exit()
	{
	}

	void Application::CheckCollision()
	{
		int quantity = m_ground.Get_Barrier_Quantity();

		for (int i = 0; i < quantity; i++) {
			sf::FloatRect barrierRect = m_ground.Get_barrier(i);

			if (barrierRect.left != 1280.0f) {
				bool collided = Collision::Collide(barrierRect, barrierRect, m_player.GetRect());
				if (collided) {
					m_states = GamesStates::lose;
					GameOver();
				}
			}
		}
	}

	bool Application::Update()
	{
		m_deltatime = m_clock.restart().asSeconds();
		m_window.setTitle("score:" + std::to_string(m_score));

		if (m_states == GamesStates::running){
			m_layer.Update(m_deltatime);
			m_closerLayer.Update(m_deltatime);
			m_ground.Update(m_deltatime);
			m_player.Update(m_deltatime);
			CheckCollision();
			m_score += static_cast<int>(10000 * m_deltatime);
			currentScoreText = m_assetManager.SetText("score:" + std::to_string(m_score), 30, sf::Color::White, 0, 0);
		}
		return m_running;
	}

	void Application::GameOver()
	{
		if (m_states == GamesStates::lose){
			scoreText = m_assetManager.SetText("score:" + std::to_string(m_score), 60, sf::Color::Black, 20, 300);
			if (m_score > m_high_score){
				m_high_score = m_score;
			}
			highScoreText = m_assetManager.SetText("high score:" + std::to_string(m_high_score), 60, sf::Color::Black, 20, 200);
		}
	}

	void Application::Render()
	{
		m_batch.Clear();
		m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });

		switch (m_states) {
		case GamesStates::menu:
			m_window.draw(menuText);
			m_window.draw(startText);
			break;

		case GamesStates::running:
			m_layer.Render(m_batch);
			m_closerLayer.Render(m_batch);
			m_ground.Render(m_batch);
			m_batch.present(m_window);
			m_player.Render(m_window);
			m_window.draw(currentScoreText);
			break;

		case GamesStates::lose:
			m_ground.Clear();
			m_layer.Clear();
			m_closerLayer.Clear();
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
			if (m_states == GamesStates::lose) {
				m_states = GamesStates::menu;
			}
		}

		if (key == sf::Keyboard::Key::S) {
			if (m_states != GamesStates::running) {
				m_states = GamesStates::running;
				Restart();
			}
		}
	}
} // !runner
