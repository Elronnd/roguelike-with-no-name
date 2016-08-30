#include <ncurses.h>

void doup(int ux, int uy) {
	mvaddch(ux-1,uy,'@');
}
void dodown(int ux, int uy) {
	mvaddch(ux+1,uy,'@');
}
void doleft(int ux, int uy) {
	mvaddch(ux,uy-1,'@');
}
void doright(int ux,int uy) {
	mvaddch(ux,uy+1,'@');
}
void remove(int y,int x) {
	mvaddch(y,x,'#');
}

int main() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	int ux=10, uy=10;

	char user_char = '@';

	mvaddch(ux,uy,user_char);
	while (TRUE) {
		switch(getch()) {
			case 'k': doup(ux,uy);
				remove(ux,uy);
				ux--;
				break;
			case 'j': dodown(ux,uy);
				remove(ux,uy);
				ux++;
				break;
			case 'h': doleft(ux,uy);
				remove(ux,uy);
				uy--;
				break;
			case 'l': doright(ux,uy);
				remove(ux,uy);
				uy++;
				break;
			case 'K':
				while (ux > 0) {
					doup(ux,uy);
					remove(ux,uy);
					ux--;
				}
				break;
			case 'q': break;
		}
	}
}
