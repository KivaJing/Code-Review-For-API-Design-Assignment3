#pragma once
#include "batch.hpp"
#include "TextManager.h"
#include "parallax_layer.h"
#include "ground.h"
#include "player.h"

enum class GamesState
{
	menu = 0,
	running = 1,
	lose = 2
};

namespace runner
{
	class Application final
	{
	public:
		Application() = default;
		void run();

	private:
		bool enter();
		void CheckCollision();
		bool Update();
		void Render();
		void GameOver();

	private:
		void on_key_pressed(const sf::Keyboard::Key key);

	private:
		sf::RenderWindow m_window;
		PrimitiveBatch   m_batch;
		sf::Clock        m_clock;
		bool             m_running = true;
		float            m_deltatime = 0.0f;
		Ground           m_ground{};
		Layer            m_layer{};
		Player           m_player{};
		TextManager      m_textManager{};
		GamesState       m_state{};
		int              m_score = 0;
		int              m_high_score = 0;
		sf::Text         menuText, startText, currentScoreText, scoreText, highScoreText, loseText, retryText;
	};
} // !runner
