#include <imgui-SFML.h>
#include <imgui.h>
#include <imgui_plot.h>

#include <stddef.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
  sf::RenderWindow window{sf::VideoMode(1280, 1024), "Trading Terminal"};
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);

  char title[255] = "ImGui Demo";

  window.setTitle(title);
  window.resetGLStates();

  sf::Clock clock;
  sf::Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, clock.restart());

    ImGui::ShowDemoWindow();

    window.clear();
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();

  return 0;
}
