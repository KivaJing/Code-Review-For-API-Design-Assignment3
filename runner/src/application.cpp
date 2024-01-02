// application.cpp

#include "application.hpp"

namespace runner
{
 
    void Application::run()
   {
      const sf::VideoMode mode{ 1280, 720 };
      const sf::Uint32 flags = sf::Style::Titlebar | sf::Style::Close;
      m_window.create(mode, "pineapple", flags);
     
      game.reset();
      
      if (!m_window.isOpen() || !enter()) {
         return;
      }
      ;
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

         if (!update()) {
            m_window.close();
         }

         render();
      }

      exit();
   }

   bool Application::enter()
   {
      return true;
   }

   void Application::exit()
   {
     //  save. ~save();
   }

   bool Application::update()
   {
      m_deltatime = m_clock.restart();
      deltatime = m_deltatime.asSeconds();
      float fps = 1 / deltatime;
      m_window.setTitle("score:"+std::to_string(game.get_score()));
      game.update(deltatime);
      return m_running;
   }

   void Application::render()
   {
      m_batch.clear();
      { 
         //// note: draw a white line from the center of the screen 
         ////       to the current mouse position
         //sf::Vector2f center_screen{ 640.0f, 360.0f };
         //m_batch.draw_line(center_screen, m_mouse_position, 1.0f, sf::Color::White);

         //// note: draw a small green circle around the current 
         ////       mouse position
         //m_batch.draw_circle(m_mouse_position, 15.0f, 12, 1.0f, sf::Color::Green);
        //  m_batch.draw_text(0, 0, "test", m_window);
        // layer1.render(m_batch);
      }
    
      m_window.clear(sf::Color{ 0x44, 0x55, 0x66, 0xff });
     

      game.render(m_batch,m_window);
      m_batch.present(m_window);
      game.render_toplayer(m_window);
     
      m_window.display();
    
   }

   void Application::on_mouse_move(const sf::Vector2f &position) 
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
          game.jump();
      }
      if (key == sf::Keyboard::Key::R)
      {
          game.reset();
      }
      if (key == sf::Keyboard::Key::S)
      {
          game.start();
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
