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

enum CMD {
	cmd_north,
	cmd_south,
	cmd_east,
	cmd_west,
	cmd_northeast,
	cmd_northwest,
	cmd_southeast,
	cmd_southwest,
	cmd_wait,
	cmd_pickup,
	cmd_quit,
	cmd_unknown
};

class Engine {
	public:
	void init();
	void run();
	void handlemove(CMD);
	void setinterface(char='d');
	void refresh();
	std::unique_ptr<BaseDisplayer> display;
	GameMap map;
	Being u;
	vector<CMD> vikeys;
	void makecmds();
	vector<char> listofvikeys {'h', 'j', 'k', 'l', 'y', 'u', 'b', 'n', '.', ',', 'q'};
};
