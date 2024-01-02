#include "game.h"
#include <iostream>

void runner::Game::start_screen(PrimitiveBatch& batch)
{
}

void runner::Game::end_screen(PrimitiveBatch& batch)
{
}

void runner::Game::end()
{
   
    ground.clear();
    layer1.clear();
    layer2.clear();
    text.clear();
    ended = true;
    started = false;
    if (score > high_score)
    {
        high_score = score;

    }
    text.clear();
    text.set_score(0);
    text.add_text("high score:" + std::to_string(high_score), { 20,200 }, 2);
    text.add_text("score:" + std::to_string(score), { 20,300 }, 2);
    text.add_text("press r to return to home page", { 20,450 }, 1);
    text.add_text("press s to return to retry", { 20,500 }, 1);
    score = 0;
}

void runner::Game::start()
{
   
    if (!started)
    {
    started = true;
    setup();

    }
    
    text.clear();
    ended = false;
}

void runner::Game::reset()
{
   
    if (!started && !ended)
    {
    ended = false;
    text.clear();
    text.add_text("SIMPLE DINO RUNNER", {20,200 }, 4);
    text.add_text("press s to start", { 350,350 }, 2);
   
    text.set_score(0);


    }
}

void runner::Game::update(float deltatime)
{
   //sf::FloatRect temp = player.get_rect();
    std::vector<sf::FloatRect>temp;
   int quantaty= ground.get_barrier_quantaty();
    for (int i = 0; i < quantaty; i++)
    {
        temp.push_back(ground.get_barrier(i));
    }

    layer1.update(deltatime);
    layer2.update(deltatime);
    ground.update(deltatime);
    player.update(deltatime);
    if (started )
    {

    score += static_cast<long>(10000 * deltatime);
    text.set_score(score);
    }
    for (int i = 0; i < quantaty; i++)
    {
       // std::cout << ground.get_barrier(i).left << std::endl;
        bool collided=collision.collision(temp[i], ground.get_barrier(i), player.get_rect());
        if (collided&&ground.get_barrier(i).left!=1280)
        {
            end();
            started = ended = false;
          
            
        }
        
    }
}

void runner::Game::render(PrimitiveBatch& batch, sf::RenderTarget& target)
{
   layer1.render(batch);
   layer2.render(batch);
    ground.render(batch);
    
}

void runner::Game::render_toplayer(sf::RenderTarget& target)
{
    text.render(target);
    if (started) {
        player.render(target);
    }
}

void runner::Game::jump()
{
    player.jump();
}



void runner::Game::setup()
{
    layer1.setup();
    layer2.setup();
    ground.setup();
    player.setup();
   
}

long runner::Game::get_score()
{
    return score;
}

long runner::Game::get_highscore()
{
    return high_score;
}
