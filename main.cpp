#include <SDL.h>
#include <iostream>
#include <stdexcept>

void throwSdlError()
{
	throw std::runtime_error(SDL_GetError());
}

int main(int argc, char* argv[] )
	{
	bool running = true;
	SDL_Window* win = nullptr;
	SDL_Surface* screen = nullptr;

	try
	{
		if( SDL_Init(SDL_INIT_VIDEO) != 0)
			throwSdlError();

		win = SDL_CreateWindow(
			"Hello!",
			 100, 100,
			 640, 480,
			 SDL_WINDOW_SHOWN);

		if (win == nullptr)
			throwSdlError();

		screen = SDL_GetWindowSurface(win);

		while(running)
			{
			SDL_Event event;
			while(SDL_PollEvent(&event))
				{
				if(event.type == SDL_QUIT)
					running = false;
				}
			SDL_FillRect( screen, NULL, 0xAAAAFFFF );
			SDL_UpdateWindowSurface( win );
			}
	}
	catch(std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
	}
