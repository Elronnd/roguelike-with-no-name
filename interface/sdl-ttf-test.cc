#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
//#include "interface.hh"

/* Exit codes:
	1: failed to initialize for whatever reason,
	2: can't load or find font
*/

const int height = 720;

TTF_Font *loadfont(const char *filename, int height=20) {
	TTF_Font *font = TTF_OpenFont(filename, height);

	if (!font) {
		printf("Unable to load font %s.\n", filename);
		printf("SDL says \"%s\"\n", TTF_GetError());
		exit(2);
	}
	
	return font;
}

//void displaychar(char inchar, SDL_Color fg, SDL_Color bg, SDL_Surface *surface, SDL_Surface *screen) {


int main() {
	SDL_Color fgcolour = {0xFF, 0xFF, 0xFF, 0}, bgcolour = {0x00, 0x00, 0x00, 0};
	SDL_Texture *screen;
	SDL_Renderer *surface;
	SDL_Rect drawingpad;
	TTF_Font *font;
	int w, h;
//	font = loadfont("dejavu_sans_mono.ttf");

	if (TTF_Init() == -1) {
		printf("TTF_Init() failed: \"%s\"", TTF_GetError());
		exit(1);
	}

	drawingpad.x = 0;
	drawingpad.y = 36;
	drawingpad.w = drawingpad.h = 50;

	// SDL_RenderFillRect for background
	font = loadfont("dejavusansmono.ttf", 30);
	// x, y, colour depth, something I have no idea what is
	screen = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height*2, height, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
//	screen = SDL_SetVideoMode(height*2, height, 32, SDL_SWSURFACE);
	Uint16 text[] = { 0x2503, 0x2503, 10 };
//	surface = TTF_RenderText_Shaded(font, "oogely boogely", fgcolour, bgcolour);
	surface = SDL_CreateTextureFromSurface(TTF_RenderUNICODE_Shaded(font, text, fgcolour, bgcolour));
	SDL_RenderCopy(surface, NULL, screen, NULL);

	fgcolour = {0xFF, 0, 0, 0};
	surface = SDL_CreateTextureFromSurface(surface, TTF_RenderUNICODE_Shaded(font, text, fgcolour, bgcolour));
	SDL_RenderCopy(surface, NULL, screen, &drawingpad);

	SDL_Flip(screen);
	sleep(2);
	TTF_SizeText(font, "|", &w, &h);
	printf("%dx%d\n", w, h);
	TTF_CloseFont(font);
	return 0;
}
