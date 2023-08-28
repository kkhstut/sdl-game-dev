#include "game.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
  int flags = 0;

  if (fullscreen) 
    flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

		if (window != 0) {
			renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer != 0)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      else
        return false;
		}
    isRunning = true;    
		return true;		
	} 
	return false;
}

void Game::handleEvents() 
{
  SDL_Event event;
  switch (SDL_PollEvent(&event)) {
    case SDL_QUIT:
      isRunning = false;
      break;

    default:
      break;
  }
}

void Game::update()
{

}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}