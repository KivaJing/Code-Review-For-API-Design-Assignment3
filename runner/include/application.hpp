#pragma once
#include "batch.hpp"
#include "AssetManager.h"
#include "collision.h"
#include "parallax_layer.h"
#include "ground.h"
#include "player.h"
#include "collision.h"

enum class GamesStates
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
		Application() {
			m_ground = std::make_unique<Ground>();
			m_layer = std::make_unique<Layer>();
		};
		void run();

	private:
		bool enter();
		void exit();
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
		std::unique_ptr<Ground> m_ground{};
		std::unique_ptr<Layer> m_layer{};
		Player           m_player{};
		TextManager      m_textManager;
		GamesStates      m_states;
		int              m_score = 0;
		int              m_high_score = 0;
		sf::Text         menuText, startText, currentScoreText, scoreText, highScoreText, loseText, retryText;
	};
} // !runner
