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
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) == -1) {
		printf("SDL_Init() failed: %s\n", SDL_GetError());
		exit(1);
	}

	if (TTF_Init() == -1) {
		printf("TTF_Init() failed: %s\n", SDL_GetError());
		exit(1);
	}

	// Title, bunch of stuff, borderless fullscreen
	// SDL_WINDOW_FULLSCREEN actually changes the video mode
	this->window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	this->loadfont("dejavu_sans_mono.ttf", 10);
}


void SDLDisplayer::end() {
	for (SDL_Texture *texture: this->tileset) {
		if (texture != nullptr) {
			SDL_DestroyTexture(texture);
		} else {
			break;
		}
	}

	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO|SDL_INIT_EVENTS);
	SDL_Quit();
}



void SDLDisplayer::loadfont(const char *filename, int height) {
	TTF_Font *font = TTF_OpenFont(filename, height);
	SDL_Surface *surface; // so we can free it
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
		surface = TTF_RenderUTF8_Blended(font, tiles::tileset()[letter].c_str(), white);
		this->tileset[letter] = SDL_CreateTextureFromSurface(this->renderer, surface);
		SDL_FreeSurface(surface);
	}

	TTF_CloseFont(font);
}

SDL_Colour SDLDisplayer::sdlcolour(RGBColour colour) {
	SDL_Colour outted {colour.r, colour.g, colour.b, 0};
	return outted;
}

// Misleading name, this only renders a character, it still has to be drawn on the screen
void SDLDisplayer::draw_char(Glyph glyph, RGBColour fg, RGBColour bg, int xoffset, int yoffset) {
	SDL_Texture *character;
	SDL_Rect tile;

	tile.x = xoffset * tile_width;
	tile.y = yoffset * tile_height;
	tile.w = tile_width;
	tile.h = tile_height;

	// Set the background colour
	SDL_SetRenderDrawColour(this->renderer, bg.r, bg.g, bg.b, 255);

	// Actually draw the background
	SDL_RenderFillRect(this->renderer, &tile);

	printf("Tile# is %d\n", glyph);
	if ((character = this->tileset[glyph]) == nullptr) {
		printf("SDLDisplayer::draw_char() was passed a nonexistent tile with ID# %d.", glyph);
		this->end();
		exit(6);
	}


	// Colourize the texture that specifies the character to be drawn
	SDL_SetTextureColorMod(character, fg.r, fg.g, fg.b);

	// And, copy to the actual renderer
	SDL_RenderCopy(this->renderer, character, nullptr, &tile);
}


void SDLDisplayer::refresh(GameMap& map) {
	int xoffset, yoffset, index; //in the lists of glyphs and colours, since we have to store them seperately
	xoffset = yoffset = index = 0;
	for (ColouredGlyphString line: map.mapspace) {
		for (Glyph glyph: line.somestr) {
			draw_char(glyph, line.fgcolourlist[index], line.bgcolourlist[index], xoffset, yoffset);
			xoffset++;
			index++;
		}
		xoffset = index = 0;
		yoffset++;
	}
	SDL_RenderPresent(this->renderer);
}


char SDLDisplayer::readchar() {
	char c = getchar();
	printf("Read character %c\n", c);
	return c;
}

void SDLDisplayer::animation_sparkle(short x, short y) {
	printf("Sparkle animation at (%d,%d)\n", x, y);
}
