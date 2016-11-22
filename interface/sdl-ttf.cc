#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
//#include <cstdlib>
#include <cstdio>
//#include <unistd.h>
//#include <cstdint>
#include "interface.hh"
#include "tile.hh"

/* Exit codes:
	4: failed to initialize for whatever reason,
	5: can't load or find font
*/

void SDLDisplayer::start() {
	if (SDL_Init() == -1) {
		printf("SDL_Init() failed: %s\n", SDL_GetError());
		exit(1);
	}

	if (TTF_Init() == -1) {
		printf("TTF_Init() failed: %s\n", SDL_GetError());
		exit(1);
	}

	this->window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	this->renderer = SDL_CreateRenderer(this->window, -1, 0);
}



void SDLDisplayer::loadfont(const char *filename, int height) {
	TTF_Font *font = TTF_OpenFont(filename, height);
	SDL_Colour white {255, 255, 255, 0};

	if (!font) {
		printf("Failed to load TTF font %s.\n", filename);
		printf("SDL says: \"%s\"\n", TTF_GetError());
		exit(5);
	}

	this->tileset.resize(255);

	for (Glyph letter: glyphs::all_glyphs) {
		// set the entry for "letter" to a texture.  We need to convert it from a surface first
		// said surface is created from a blended rendering of white text from our font
		this->tileset[letter] = SDL_CreateTextureFromSurface(this->renderer, TTF_RenderUTF8_Blended(font, tiles::tileset()[letter].c_str(), white));
	}

	TTF_CloseFont(font);
}

SDL_Colour SDLDisplayer::sdlcolour(RGBColour colour) {
	SDL_Colour outted {colour.r, colour.g, colour.b, 0};
	return outted;
}

void SDLDisplayer::draw_char(str character /* yes, yes... */, RGBColour fg, RGBColour bg, int xoffset, int yoffset) {
	// Set the colour to be drawn
	SDL_SetRenderDrawColour(this->renderer, bg.r, bg.g, bg.b, 255);

	surface
}
