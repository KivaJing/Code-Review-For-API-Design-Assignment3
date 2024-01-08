#include "game.h"
#include <iostream>

static const char* kPlayerFrame1ID = "player1";
static const char* kPlayerFrame2ID = "player2";

void runner::Game::End()
{
   
    ground.Clear();
    layer.Clear();
    closerLayer.Clear();
    text.Clear();
    ended = true;
    started = false;
    if (score > high_score)
    {
        high_score = score;

    }
    text.Clear();
    text.set_score(0);
    text.add_text("high score:" + std::to_string(high_score), { 20,200 }, 2);
    text.add_text("score:" + std::to_string(score), { 20,300 }, 2);
    text.add_text("press r to return to home page", { 20,450 }, 1);
    text.add_text("press s to return to retry", { 20,500 }, 1);
    score = 0;
}

void runner::Game::Start()
{
    if (!started)
    {
        started = true;
        Setup();
    }
    
    text.Clear();
    ended = false;
}

void runner::Game::Reset()
{
    if (!started && !ended)
    {
        ended = false;
        text.Clear();
        text.add_text("SIMPLE DINO RUNNER", { 20, 200 }, 4);
        text.add_text("press s to start", { 350, 350 }, 2);
   
        text.set_score(0);
    }
}

void runner::Game::Update(float deltatime)
{
    std::vector <sf::FloatRect> temp;
    int quantaty = ground.Get_barrier_quantaty();
    for (int i = 0; i < quantaty; i++)
    {
        temp.push_back(ground.Get_barrier(i));
    }

    layer.Update(deltatime);
    closerLayer.Update(deltatime);
    ground.Update(deltatime);
    player.Update(deltatime);

    if (started)
    {
        score += static_cast<long>(10000 * deltatime);
        text.set_score(score);
    }

    for (int i = 0; i < quantaty; i++)
    {
        bool collided = collision.collision(temp[i], ground.Get_barrier(i), player.GetRect());
        if (collided && ground.Get_barrier(i).left != 1280)
        {
            End();
            started = ended = false; 
        }
        
    }
}

void runner::Game::Render(PrimitiveBatch& batch, sf::RenderTarget& target)
{
    layer.Render(batch);
    closerLayer.Render(batch);
    ground.Render(batch);
}

void runner::Game::render_toplayer(sf::RenderTarget& target)
{
    text.Render(target);
    if (started) {
        player.Render(target);
    }
}

void runner::Game::Jump()
{
    player.Jump();
}

void runner::Game::Setup()
{
    assetManager.LoadTexture(kPlayerFrame1ID, "assets/playerFrame1.png");
    assetManager.LoadTexture(kPlayerFrame2ID, "assets/playerFrame2.png");

    layer.Setup({ 20,120,50,150,150, false });
    closerLayer.Setup({ 50,250,100,300,250, true });
    ground.Setup();
    player.Setup(assetManager.GetTexture(kPlayerFrame1ID), assetManager.GetTexture(kPlayerFrame2ID));
}

long runner::Game::get_score()
{
    return score;
}

long runner::Game::get_highscore()
{
    return high_score;
}
