#pragma once

#include <SDL2/SDL.h>

enum AppState { OPEN, EXIT };

class Application {
  public:
    Application();
    Application(int width, int height);
    ~Application();

    void run();

  private:
    void initSystems();
    void proccessInput();
    void appLoop();
    int _screenWidth;
    int _screenHeight;
    AppState _currentState;
    SDL_Window* _window;
    SDL_Surface* _screenSurface;
};