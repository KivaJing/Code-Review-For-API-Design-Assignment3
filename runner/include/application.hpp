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
		Application() = default;
		void run();

	private:
		bool enter();
		void exit();
		bool Update();
		void Render();
		void GameOver();
		void Restart();

	private:
		void on_mouse_move(const sf::Vector2f& position);
		void on_key_pressed(const sf::Keyboard::Key key);
		void on_key_released(const sf::Keyboard::Key key);
		void on_button_pressed(const sf::Mouse::Button button);
		void on_button_released(const sf::Mouse::Button button);

	private:
		sf::RenderWindow m_window;
		PrimitiveBatch   m_batch;
		sf::Clock        m_clock;
		sf::Vector2f     m_mouse_position;
		bool             m_running = true;
		float            m_deltatime;
		Layer            m_layer;
		Layer            m_closerLayer;
		Ground           m_ground;
		Player           m_player;
		AssetManager     m_assetManager;
		GamesStates      m_states;
		long             m_score = 0;
		long             m_high_score = 0;
		sf::Text         menuText, startText, currentScoreText, scoreText, highScoreText, loseText, retryText;
	};
} // !runner
