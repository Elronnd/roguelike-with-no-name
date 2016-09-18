#include <string>
#include "stddef.hh"
#include "stdlib.hh"
#pragma once
class BaseDisplayer {
	public:
	virtual void refresh(GameMap& map) = 0;
	virtual void animation_sparkle(short, short) = 0;
/*	virtual void animation_line(short, short, short, short,RGBColour) = 0;
	virtual void animation_gradientline(short, short, short, short, RGBColour, RGBColour) = 0;*/
	virtual char getchar() = 0;
};
class JSONDisplayer: public BaseDisplayer {
	private:
	str rgbstr2json(ColouredString);
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short,RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char getchar() override;
};

class DebugDisplayer: public BaseDisplayer {
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short,RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char getchar() override;
};
