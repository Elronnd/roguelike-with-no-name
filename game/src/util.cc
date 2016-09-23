#include "interface.hh"
#include "main.hh"
#include <memory>

// dynamically set the window type at runtime
void Engine::setinterface(char type) {
	switch(type) {
		case 'd':
		case 'D': this->display = std::make_unique<DebugDisplayer>();
			  break;
		case 'j':
		case 'J': this->display = std::make_unique<JSONDisplayer>();
			  break;
		case 'u':
		case 'U': this->display = std::make_unique<UncursedDisplayer>();
			  break;
		default: this->display = std::make_unique<UncursedDisplayer>();
	}
}

void Engine::refresh() {
	this->display->refresh(this->map);
}
