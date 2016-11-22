#include <SDL2/SDL.h>
#include <unistd.h>

int main() {
	SDL_Rect tehrect;
	SDL_Renderer *screen;
	SDL_Texture *surface;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		exit(5);
	}

	tehrect.x = 0;
	tehrect.y = 0;
	tehrect.w = 50;
	tehrect.h = 100;
	SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	screen = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(screen, 255, 0, 0, 255);

	SDL_RenderFillRect(screen, &tehrect);

	SDL_RenderPresent(screen);
	sleep(3);
	SDL_Quit();
	return 0;
}
