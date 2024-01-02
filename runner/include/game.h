#pragma once
#include "batch.hpp"
#include "collision.h"
#include"parallax_layer1.h"
#include"parallax_layer2.h"
#include "ground.h"
#include "text.h"
#include "player.h"
#include "collision.h"
//#include "save.h"
namespace runner
{
	
	class Game
	{
	private:
		
		void start_screen(PrimitiveBatch& batch);
		void end_screen(PrimitiveBatch& batch);
		
		bool started = false;
		bool ended = false;

		Layer1 layer1;
		Layer2 layer2;
		Collision collision;
		Ground ground;
		Text text;
		Player player;
		long score = 0;
		long high_score = 0;
		void end();
		void setup();
	public:
		void start();
		void reset();
		void update(float deltatime);
		void render(PrimitiveBatch& batch, sf::RenderTarget& target);
		void render_toplayer(sf::RenderTarget& target);
		void jump();
		long get_score();
		long get_highscore();
	};
}