#include "general.h"

const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 800;

SDL_Rect shipPos;
SDL_Renderer *renderer=NULL; //To make global use
SDL_Window *window=NULL; //always set any pointer to NULL prevent mem leaks
SDL_Surface *screen=NULL;

//Quad functionality
SDL_Rect quad1;
SDL_Rect quad2;
SDL_Rect quad3;
SDL_Rect quad4;

int main(int argc, char ** argv)
{
    
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	createWindow();
    
	SDL_Surface * image = IMG_Load ("../img/playerShip.png"); 
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	int shipW=image->w; //getting size of the ship.
	int shipH=image->h;    
	shipPos= { ((SCREEN_WIDTH/2)-shipW),((SCREEN_HEIGHT/2)-shipH),shipW,shipH };	 
   
	quad2.x = SCREEN_WIDTH / 2; 
	quad2.y = 0; 
	quad2.w = SCREEN_WIDTH / 2; 
	quad2.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(renderer,&quad2); 	

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
        SDL_RenderClear( renderer );
        SDL_RenderCopy(renderer, texture, NULL, &shipPos);
        SDL_RenderPresent( renderer );
	
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


void createWindow()
{	
	if(SDL_Init(SDL_INIT_VIDEO)==-1)
		cerr << "Video initialiazation failure: " << SDL_GetError() << endl;
	else
	{
		window=SDL_CreateWindow("LAIRSPACE",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if (window==NULL)
		{
			cerr << "Window couldn't be created" << SDL_GetError() << endl;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED);
			if( renderer == NULL )
			{
				cout << "SDL Error:" << SDL_GetError() << endl;
			}
			else		
			{				
				//Initialize renderer adding a black background
				SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
			}
		}
	}

}
