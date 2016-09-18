#include <vector>
#include <string>
#include "stddef.hh"

#pragma once

/* mapping from tile to unicode characters */
/* Maybe some other stuff.  We"ll see. */

inline strlist tileset() {
	static strlist tileslist;
	tileslist.resize(256);


	tileslist[middot]	= "·";
	tileslist[at] 		= "@";

	tileslist[light_square]  = "░";
	tileslist[medium_square] = "▒";
	tileslist[dark_square]   = "▓";
	tileslist[full_square]   = "█";

	tileslist[wall_horizontal_thick] = "━";
	tileslist[wall_horizontal_thin] = "─";
	tileslist[wall_horizontal_thinleft_thickright] = "╼";
	tileslist[wall_horizontal_thickleft_thinright] = "╾";
	tileslist[wall_horizontal_thick_left] = "╸";
	tileslist[wall_horizontal_thick_right] = "╺";
	tileslist[wall_horizontal_thin_left] = "╴";
	tileslist[wall_horizontal_thin_right] = "╶";
	tileslist[wall_horizontal_double] = "═";
	tileslist[dash] = "-";
	tileslist[underscore] = "_";
	tileslist[equals] = "=";

	tileslist[wall_vertical_thick] = "┃";
	tileslist[wall_vertical_thin] = "│";
	tileslist[wall_vertical_thintop_thickbottom] = "╽";
	tileslist[wall_vertical_thicktop_thinbottom] = "╿";
	tileslist[wall_vertical_thick_top] = "╹";
	tileslist[wall_vertical_thick_bottom] = "╻";
	tileslist[wall_vertical_thin_top] = "╵";
	tileslist[wall_vertical_thin_bottom] = "╷";
	tileslist[wall_vertical_double] = "║";

	tileslist[wall_lowerright_thick] = "┛";
	tileslist[wall_lowerright_thinbottom_thickside] = "┚";
	tileslist[wall_lowerright_thickbottom_thinside] = "┙";
	tileslist[wall_lowerright_thin] = "┘";
	tileslist[wall_lowerright_curved] = "╯";
	tileslist[wall_lowerright_double] = "╝";
	tileslist[wall_lowerright_doublebottom_singleside] = "╛";
	tileslist[wall_lowerright_singlebottom_doubleside] = "╜";

	tileslist[wall_lowerleft_thick] = "┗";
	tileslist[wall_lowerleft_thinbottom_thickside] = "┖";
	tileslist[wall_lowerleft_thickbottom_thinside] = "┕";
	tileslist[wall_lowerleft_thin] = "└";
	tileslist[wall_lowerleft_curved] = "╰";
	tileslist[wall_lowerleft_double] = "╚";
	tileslist[wall_lowerleft_doublebottom_singleside] = "╘";
	tileslist[wall_lowerleft_singlebottom_doubleside] = "╙";

	tileslist[wall_upperright_thick] = "┓";
	tileslist[wall_upperright_thicktop_thinside] = "┑";
	tileslist[wall_upperright_thintop_thickside] = "┒";
	tileslist[wall_upperright_thin] = "┐";
	tileslist[wall_upperright_curved] = "╮";
	tileslist[wall_upperright_double] = "╗";
	tileslist[wall_uperright_doubletop_singleside] = "╕";
	tileslist[wall_uperright_singletop_doubleside] = "╖";

	tileslist[wall_upperleft_thick] = "┏";
	tileslist[wall_upperleft_thicktop_thinside] = "┍";
	tileslist[wall_upperleft_thintop_thickside] = "┎";
	tileslist[wall_upperleft_thin] = "┌";
	tileslist[wall_upperleft_curved] = "╭";
	tileslist[wall_upperleft_double] = "╔";
	tileslist[wall_upperleft_doubletop_singleside] = "╒";
	tileslist[wall_upperleft_singletop_doubleside] = "╓";

	tileslist[wall_t_thick] = "╋";
	tileslist[wall_t_thintop_thinright_thinbottom_thickleft] = "┽";
	tileslist[wall_t_thintop_thickright_thinbottom_thinleft] = "┾";
	tileslist[wall_t_thintop_thickright_thinbottom_thickleft] = "┿";
	tileslist[wall_t_thicktop_thinright_thinbottom_thinleft] = "╀";
	tileslist[wall_t_thintop_thinright_thickbottom_thinleft] = "╁";
	tileslist[wall_t_thicktop_thinright_thickbottom_thinleft] = "╂";
	tileslist[wall_t_thicktop_thinright_thinbottom_thickleft] = "╃";
	tileslist[wall_t_thicktop_thickright_thinbottom_thinleft] = "╄";
	tileslist[wall_t_thintop_thinright_thickbottom_thickleft] = "╅";
	tileslist[wall_t_thintop_thickright_thickbottom_thinleft] = "╆";
	tileslist[wall_t_thicktop_thickright_thinbottom_thickleft] = "╇";
	tileslist[wall_t_thintop_thickright_thickbottom_thickleft] = "╈";
	tileslist[wall_t_thicktop_thinright_thickbottom_thickleft] = "╉";
	tileslist[wall_t_thicktop_thickright_thickbottom_thinleft] = "╊";
	tileslist[wall_t_thin] = "┼";
	tileslist[wall_t_double] = "╬";
	tileslist[wall_t_doubletop_singleright_doubledown_singleleft] = "╫";
	tileslist[wall_t_singletop_doubleright_singledown_doubleleft] = "╪";

	tileslist[t_noleft_thick] = "┣";
	tileslist[t_noleft_thintop_thickright_thickbottom] = "┢";
	tileslist[t_nolefft_thicktop_thickright_thinbottom] = "┡";
	tileslist[t_noleft_thicktop_thinright_thickbottom] = "┠";
	tileslist[t_noleft_thintop_thinright_thickbottom] = "┟";
	tileslist[t_noleft_thicktop_thinright_thinbottom] = "┞";
	tileslist[t_noleft_thintop_thickright_thinbottom] = "┝";
	tileslist[t_noleft_thing] = "├";

	tileslist[crossing_slashes] = "╳";
	tileslist[slash_forward] = "╱";
	tileslist[slash_back] = "╲";
	return tileslist;
}
