#include "application.hpp"

namespace runner
{

	void Application::run()
	{
		const sf::VideoMode mode{ 1280, 720 };
		const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
		m_window.create(mode, "pineapple", flags);

		game.Reset();

		if (!m_window.isOpen() || !enter()) {
			return;
		}

		m_window.setKeyRepeatEnabled(false);
		while (m_window.isOpen()) {
			sf::Event event;
			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::MouseMoved) {
					on_mouse_move({ float(event.mouseMove.x), float(event.mouseMove.y) });
				}
				else if (event.type == sf::Event::MouseButtonPressed) {
					on_button_pressed(event.mouseButton.button);
				}
				else if (event.type == sf::Event::MouseButtonReleased) {
					on_button_released(event.mouseButton.button);
				}
				else if (event.type == sf::Event::KeyPressed) {
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
		return true;
	}

	void Application::exit()
	{
	}

	bool Application::Update()
	{
		m_deltatime = m_clock.restart();
		deltatime = m_deltatime.asSeconds();
		float fps = 1 / deltatime;
		m_window.setTitle("score:" + std::to_string(game.get_score()));
		game.Update(deltatime);
		return m_running;
	}

	void Application::Render()
	{
		m_batch.Clear();
		{
		}

		m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });


		game.Render(m_batch, m_window);
		m_batch.present(m_window);
		game.render_toplayer(m_window);

		m_window.display();

	}

	void Application::on_mouse_move(const sf::Vector2f& position)
	{
		m_mouse_position = position;
	}

	void Application::on_key_pressed(const sf::Keyboard::Key key)
	{
		if (key == sf::Keyboard::Key::Escape) {
			m_running = false;
		}
		if (key == sf::Keyboard::Key::Space)
		{
			game.Jump();
		}
		if (key == sf::Keyboard::Key::R)
		{
			game.Reset();
		}
		if (key == sf::Keyboard::Key::S)
		{
			game.Start();
		}
	}

	void Application::on_key_released(const sf::Keyboard::Key key)
	{
	}

	void Application::on_button_pressed(const  sf::Mouse::Button button)
	{
	}

	void Application::on_button_released(const sf::Mouse::Button button)
	{
	}
} // !runner
