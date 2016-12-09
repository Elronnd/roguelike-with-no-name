#include "interface.hh"
#include "main.hh"
#include <memory>

// dynamically set the window type at runtime
void Engine::setinterface(char type) {
	switch(type) {
		case 'd':
		case 'D': this->display = std::make_unique<DebugDisplayer>();
			  break;
		case 's':
		case 'S': this->display = std::make_unique<SDLDisplayer>();
			  break;
		default: this->display = std::make_unique<DebugDisplayer>();
	}
}

void Engine::refresh() {
	this->display->refresh(this->map);
}

void Engine::makecmds() {
	this->vikeys["k"] = cmd_north;
	this->vikeys["j"] = cmd_south;
	this->vikeys["l"] = cmd_east;
	this->vikeys["h"] = cmd_west;
	this->vikeys["y"] = cmd_northwest;
	this->vikeys["b"] = cmd_southwest;
	this->vikeys["u"] = cmd_northeast;
	this->vikeys["n"] = cmd_southeast;
	this->vikeys["."] = cmd_wait;
	this->vikeys[","] = cmd_pickup;
	this->vikeys["q"] = cmd_quit;
}
