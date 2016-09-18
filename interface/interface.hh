#include <string>
#include "stddef.hh"
#include "stdlib.hh"

/* API description for the displayer */

#pragma once
class BaseDisplayer {
	public:
	virtual void refresh(GameMap&) = 0;
	virtual void animation_sparkle(short, short) = 0;
/*	virtual void animation_line(short, short, short, short,RGBColour) = 0;
	virtual void animation_gradientline(short, short, short, short, RGBColour, RGBColour) = 0;*/
	virtual char readchar() = 0;
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
};

class DebugDisplayer: public BaseDisplayer {
	public:
	void refresh(GameMap&) override;
	void animation_sparkle(short, short) override;
/*	void animation_line(short, short, short, short,RGBColour) override;
	void animation_gradientline(short, short, short, short, RGBColour, RGBColour) override;*/
	char readchar() override;
};
