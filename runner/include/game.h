#pragma once
#include "batch.hpp"
#include "collision.h"
#include"parallax_layer.h"
#include "ground.h"
#include "text.h"
#include "player.h"
#include "collision.h"

namespace runner
{
	
	class Game
	{
	private:
		
		void start_screen(PrimitiveBatch& batch);
		void end_screen(PrimitiveBatch& batch);
		
		bool started = false;
		bool ended = false;

		Layer layer;
		Layer closerLayer;
		Collision collision;
		Ground ground;
		Text text;
		Player player;
		long score = 0;
		long high_score = 0;
		void end();
		void Setup();
	public:
		void start();
		void reset();
		void Update(float deltatime);
		void Render(PrimitiveBatch& batch, sf::RenderTarget& target);
		void render_toplayer(sf::RenderTarget& target);
		void jump();
		long get_score();
		long get_highscore();
	};
}