#include "Core/Application.h"
#include <iostream>

Application::Application(int width, int height)
    : _window(nullptr)
    , _screenWidth(width)
    , _screenHeight(height)
    , _currentState(OPEN) {}

Application::Application()
    : Application::Application(1024, 768) {}

Application::~Application() {}

void Application::run() {
    initSystems();

    appLoop();

    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Application::initSystems() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error:"
                  << " " << SDL_GetError();
    }

    _window =
        SDL_CreateWindow("MicroCad", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth,
                         _screenHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if (_window == nullptr) {
        std::cout << "Window could not be created! SDL_Error:"
                  << " " << SDL_GetError();
    } else {
        // Get window surface
        _screenSurface = SDL_GetWindowSurface(_window);

        // Fill the surface white
        SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));

        // Update the surface
        SDL_UpdateWindowSurface(_window);
    }
}

void Application::proccessInput() {
    SDL_Event evnt;
    while (SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
        case SDL_QUIT:
            _currentState = EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
            break;
        default:
            break;
        }
    };
}
void Application::appLoop() {
    while (_currentState != EXIT) {
        proccessInput();
    }
}