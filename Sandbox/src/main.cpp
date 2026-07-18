#include <SDL2/SDL.h>
#include <iostream>


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL initialization failed: "
                  << SDL_GetError()
                  << std::endl;

        return 1;
    }


    SDL_Window* window = SDL_CreateWindow(
        "Graphics Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );


    if (window == nullptr)
    {
        std::cout << "Window creation failed: "
                  << SDL_GetError()
                  << std::endl;

        SDL_Quit();
        return 1;
    }


    bool running = true;


    while (running)
    {
        SDL_Event event;


        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }


        // Здесь позже будет:
        // Renderer::Clear()
        // Renderer::Render()
        // Renderer::Present()


        SDL_Delay(16); // ограничение примерно 60 FPS
    }


    SDL_DestroyWindow(window);

    SDL_Quit();


    return 0;
}