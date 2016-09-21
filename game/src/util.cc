#include "interface.hh"
#include "main.hh"
#include <memory>
void Engine::setinterface(bool wantdebug) {
	if (wantdebug) {
		this->display = std::make_unique<DebugDisplayer>();
	} else {
		this->display = std::make_unique<JSONDisplayer>();
	}
}

void Engine::refresh() {
	this->display->refresh(this->map);
}



