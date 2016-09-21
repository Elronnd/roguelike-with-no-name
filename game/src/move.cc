#include "main.hh"

void Engine::handlemove(char inchar) {
	switch(inchar) {
		case 'h':
			if (u.ux > 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.ux--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'l':
			if (u.ux < MAX_COLS-1) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.ux++;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'k':
			if (u.uy > 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'j':
			if (u.uy < MAX_ROWS-1) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy++;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
			display->refresh(map);
			break;
		default: display->refresh(map); break;
	}
}
