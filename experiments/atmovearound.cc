#include <ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>

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
	mvaddch(y,x,' ');
}
void paint(int y,int x) {
	mvaddch(y,x,'#');
}

int xsize() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size.ws_col;
}

int ysize() {
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return size.ws_row;
}

int main() {
	int maxy;
	int maxx;
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
			case 'k':
				if (ux > 0 ) {
					doup(ux,uy);
					remove(ux,uy);
					ux--;
				}
				break;
			case 'j':
				if (ux <= xsize()) {
					dodown(ux,uy);
					remove(ux,uy);
					ux++;
				}
				break;
			case 'h':
				if (uy > 0) {
					doleft(ux,uy);
					remove(ux,uy);
					uy--;
				}
				break;
			case 'l': doright(ux,uy);
				remove(ux,uy);
				uy++;
				break;
			case 'q': return 0;
		}
	}
}
