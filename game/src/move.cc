#include "main.hh"

void Engine::handlemove(CMD cmd) {
	switch(cmd) {
		case cmd_west:
			if (u.ux > 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				map.mapspace[u.uy].somestr[--u.ux] = at;
			}
			break;
		case cmd_east:
			if (u.ux < MAX_COLS-1) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				map.mapspace[u.uy].somestr[++u.ux] = at;
			}
			break;
		case cmd_north:
			if (u.uy > 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				map.mapspace[--u.uy].somestr[u.ux] = at;
			}
			break;
		case cmd_south:
			if (u.uy < MAX_ROWS-1) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				map.mapspace[++u.uy].somestr[u.ux] = at;
			}
			break;
#if 0
		case cmd_northwest:
			if ((u.ux > 0) && (u.uy > 0)) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy--;
				u.ux--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
			break;
		case cmd_southwest:
			if ((u.uy > 0) || (u.uy < MAX_ROWS-1)) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy++;
				u.ux--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
			break;
#endif
		default: break; // until later
	}
	map.x = u.ux;
	map.y = u.uy;
	refresh();
}
