#include <string>
#include "stddef.hh"
#include "interface.hh"
#pragma once

class Being {
	public:
	bool gender; // true is male, false is female
	unsigned char xlvl;
	int xp;
	int hp, maxhp, mp, maxmp;
	int str, dex, con, wis, intel, cha;

	unsigned char ux, uy;

	std::string name, race;

	bool ismale() {
		return gender;
	}
	bool isfemale() {
		return !gender;
	}
};

class Engine {
	public:
	void handlemove(char);
	void setinterface(bool);
	void refresh();
//	DebugDisplayer *display = new DebugDisplayer;
	std::unique_ptr<BaseDisplayer> display;
	GameMap map;
	Being u;
};
