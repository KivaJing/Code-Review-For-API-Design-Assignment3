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
		Application() : m_running(true), m_deltatime(0.0f), m_states(GamesStates::menu), m_score(0), m_high_score(0) {};
		void run();

	private:
		bool enter();
		void Restart();
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
		bool             m_running;
		float            m_deltatime;
		Layer            m_layer;
		Layer            m_closerLayer;
		Ground           m_ground;
		Player           m_player;
		AssetManager     m_assetManager;
		GamesStates      m_states;
		int              m_score;
		int              m_high_score;
		sf::Text         menuText, startText, currentScoreText, scoreText, highScoreText, loseText, retryText;
	};
} // !runner
