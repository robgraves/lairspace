
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event event;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("LAIR SPACE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load ("../img/playerShip.png"); 
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    //game loop
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }   
    }

    //cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
