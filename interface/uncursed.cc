#include <cstdlib>
#include <locale>
#include <string>
#include <iostream>
#include "interface.hh"
#include "tile.hh"
#include "uncursed.h"
#include "stdlib.hh"
#include "stddef.hh"


#define x() getmaxx(win)
#define y() getmaxy(win)

void UncursedDisplayer::start(int *argc, char **argp) {
	setlocale(LC_ALL, "en_US.utf8");
	initialize_uncursed(argc, argp);
	this->win = initscr();
	this->currwin = newwin(80, 20, 1, 1);
	curs_set(0);
}

void UncursedDisplayer::refresh(GameMap& map) {
	int row, col;
	row = col = 0;
	col++;
	for (ColouredTileString line: map.mapspace) {
		for (Tile tile: line.somestr) {
			mvwaddwstr(this->win, col, row, (wchar_t *) wtileset()[tile].c_str());
			row++;
		}
		col++;
		row=0;
	}
//	refresh();
	wrefresh(this->win);
}

char UncursedDisplayer::readchar() {
	return getch();
//	return  'f';
}

void UncursedDisplayer::animation_sparkle(short x, short y) {
	(void) x;
	(void) y;
}
