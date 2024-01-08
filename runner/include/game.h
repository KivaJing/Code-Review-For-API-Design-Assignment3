#pragma once
#include "batch.hpp"
#include "AssetManager.h"
#include "collision.h"
#include "parallax_layer.h"
#include "ground.h"
#include "text.h"
#include "player.h"
#include "collision.h"

namespace runner
{
	class Game
	{
	private:
		bool started = false;
		bool ended = false;

		Layer layer;
		Layer closerLayer;
		Collision collision;
		Ground ground;
		Text text;
		Player player;
		AssetManager assetManager;

		long score = 0;
		long high_score = 0;
		void Setup();
		void End();

	public:
		void Start();
		void Reset();
		void Update(float deltatime);
		void Render(PrimitiveBatch& batch, sf::RenderTarget& target);
		void render_toplayer(sf::RenderTarget& target);
		void Jump();
		long get_score();
		long get_highscore();
	};
}