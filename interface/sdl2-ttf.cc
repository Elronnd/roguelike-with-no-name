#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>

const int height = 720;
const int max_rows = 80;
const int max_cols = 30;

class SDLThingy {
	public:

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Color fg1, fg2 = {255, 255, 255, 0}, bg1, bg2;
	TTF_Font *font;

	TTF_Font *loadfont(const char *filename, int height=20) {
		this->font = TTF_OpenFont(filename, height);
	
		if (!this->font) {
			printf("Unable to load font %s.\n", filename);
			printf("SDL says \"%s\"\n", TTF_GetError());
			exit(2);
		}
	}


	void drawchar(uint16_t ch) {
//		int xoffset = x*w, yoffset = y*h;
		int xoffset = 0, yoffset = 0;
		SDL_Rect ourrect;
		SDL_Texture *outted;

		ourrect.x = 0;
		ourrect.y = 0;
		ourrect.w = 50;
		ourrect.h = 50;

		SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);

		SDL_RenderFillRect(this->renderer, &ourrect);

		outted = SDL_CreateTextureFromSurface(this->renderer, TTF_RenderGlyph_Blended(this->font, ch, this->fg2));

		SDL_SetTextureColorMod(outted, 5, 255, 0);

		SDL_RenderCopy(renderer, outted, NULL, &ourrect);


		SDL_RenderPresent(renderer);
	}
	
};


int main() {
#if 0
	SDL_Color fg1 = {0xFF, 0xFF, 0xFF}, fg2 = {0xFF, 0, 0, 0xFF}, bg1 = {0, 0, 0}, bg2 = {0, 0, 0, 0xFF};

	SDL_Renderer *screen;
	SDL_Texture *surface;
	SDL_Window *window;
	TTF_Font *font;
	SDL_Rect dest = {0, 0, 500, 750};
	int w, h;

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		printf("Error: you need the PNG library.\n");
		printf("IMG_Init(): \"%s\"\n", IMG_GetError());
		exit(3);
	}
#endif

	SDLThingy ourthingy;
	

	if (TTF_Init() == -1) {
		printf("TTF_Init() failed: %s\n", SDL_GetError());
		exit(1);
	}
#if 0

	SDL_Surface *f = IMG_Load("rowena.png");
	if (!f) {
		printf("Couldn't load rowena.png.");
		printf("SDL says \"%s\"", IMG_GetError());
		exit(5);
	}

	SDL_SetWindowIcon(window, f);
#endif

	ourthingy.loadfont("dejavusansmono.ttf", 150);

	// wm title, something, something, width, height, fullscreen
	ourthingy.window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

	ourthingy.renderer = SDL_CreateRenderer(ourthingy.window, -1, 0);

//	TTF_SetFontHinting(font, TTF_HINTING_LIGHT);
	ourthingy.drawchar(0x2501);
//	SDL_RenderCopy(screen, surface, NULL, &dest);
//	SDL_RenderPresent(screen);
//	SDL_GetWindowSize(window, &w, &h);
//	printf("%dx%d\n", w, h);
	sleep(2);
	return 0;
}
