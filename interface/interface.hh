#include <string>
#include "stddef.hh"
#include "stdlib.hh"
#include <SDL2/SDL.h>

/* API description for the displayer */

#pragma once

#define SDL_SetRenderDrawColour SDL_SetRenderDrawColor

class BaseDisplayer {
	public:
	virtual ~BaseDisplayer() = default;
	virtual void refresh(GameMap&) = 0;
	virtual void animation_sparkle(short, short) = 0;
/*	virtual void animation_line(short, short, short, short,RGBColour) = 0;
	virtual void animation_gradientline(short, short, short, short, RGBColour, RGBColour) = 0;*/
	virtual char readchar() = 0;
	virtual void start() = 0;
	virtual void end() = 0;
};
class JSONDisplayer: public BaseDisplayer {
	private:
	str rgbstr2json(ColouredString);
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short,RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char readchar() override;
	void start() override;
	void end() override;
};

class DebugDisplayer: public BaseDisplayer {
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short,RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char readchar() override;
	void start() override;
	void end() override;
};

class SDLDisplayer: public BaseDisplayer {
	private:
	void loadfont(const char *filename, int height=100);
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Colour sdlcolour(RGBColour);
	vector<SDL_Texture*> tileset;
	void draw_char(Glyph, RGBColour, RGBColour, int, int);
	int width, height;
	int tile_width = 10, tile_height = 2*tile_width;
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short, RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char readchar() override;
	void start() override;
	void end() override;
};
