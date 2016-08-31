#include <vector>

#ifndef STDDEF_HH
#define STDDEF_HH

using array = std::vector<int>;

/* includes defines like what the map is */
/* also used by graphicals */

enum tiles {
	light_square, /* they have gradients of how bright they are, but that's
                       * handled elsewhere */
	dark_square,

	/* It turns out that there are a *lot* of different box drawing
	 * and we want to utilize them all to show, say, partially dug through
	 * walls.  The price is this huge enum */
	wall_horizontal_thick,			// ━
	wall_horizontal_thin,			// ─
	wall_horizontal_thinleft_thickright,	// ╼
	wall_horizontal_thickleft_thinright,	// ╾
	wall_horizontal_thick_left,		// ╸
	wall_horizontal_thick_right,		// ╺
	wall_horizontal_thin_left,		// ╴
	wall_horizontal_thin_right,		// ╶
	wall_horizontal_double,			// ═
	dash,					/* -, equates to wall_horizontal_thick in
						 * des-files */
	underscore,				/* _, equates to wall_horizontal_thin in
						 * des-files */
	equals,					/* =, equates to wall_horizontal_double in
						 * des-files */

	wall_vertical_thick,			// ┃
	wall_vertical_thin,			// │
	wall_vertical_thintop_thickbottom,	// ╽
	wall_vertical_thicktop_thinbottom,	// ╿
	wall_vertical_thick_top,		// ╹
	wall_vertical_thick_bottom,		// ╻
	wall_vertical_thin_top,			// ╵
	wall_vertical_thin_bottom,		// ╷
	wall_vertical_double,			// ║

	wall_lowerright_thick,			// ┛
	wall_lowerright_thinbottom_thickside,	// ┚
	wall_lowerright_thickbottom_thinside,	// ┙
	wall_lowerright_thin,			// ┘
	wall_lowerright_curved,			// ╯
	wall_lowerright_double,			// ╝
	wall_lowerright_doublebottom_singleside,// ╛
	wall_lowerright_singlebottom_doubleside,// ╜

	wall_lowerleft_thick,			// ┗
	wall_lowerleft_thinbottom_thickside,	// ┖
	wall_lowerleft_thickbottom_thinside,	// ┕
	wall_lowerleft_thin,			// └
	wall_lowerleft_curved,			// ╰
	wall_lowerleft_double,			// ╚
	wall_lowerleft_doublebottom_singleside,	// ╘
	wall_lowerleft_singlebottom_doubleside,	// ╙

	wall_upperright_thick,			// ┓
	wall_upperright_thicktop_thinside,	// ┑
	wall_upperright_thintop_thickside,	// ┒
	wall_upperright_thin,			// ┐
	wall_upperright_curved,			// ╮
	wall_upperright_double,			// ╗
	wall_uperright_doubletop_singleside,	// ╕
	wall_uperright_singletop_doubleside,	// ╖

	wall_upperleft_thick,			// ┏
	wall_upperleft_thicktop_thinside,	// ┍
	wall_upperleft_thintop_thickside,	// ┎
	wall_upperleft_thin,			// ┌
	wall_upperleft_curved,			// ╭
	wall_upperleft_double,			// ╔
	wall_upperleft_doubletop_singleside,	// ╒
	wall_upperleft_singletop_doubleside,	// ╓

	wall_t_thick,					// ╋
	wall_t_thintop_thinright_thinbottom_thickleft,	// ┽
	wall_t_thintop_thickright_thinbottom_thinleft,	// ┾
	wall_t_thintop_thickright_thinbottom_thickleft,	// ┿
	wall_t_thicktop_thinright_thinbottom_thinleft,	// ╀
	wall_t_thintop_thinright_thickbottom_thinleft,	// ╁
	wall_t_thicktop_thinright_thickbottom_thinleft,	// ╂
	wall_t_thicktop_thinright_thinbottom_thickleft,	// ╃
	wall_t_thicktop_thickright_thinbottom_thinleft,	// ╄
	wall_t_thintop_thinright_thickbottom_thickleft,	// ╅
	wall_t_thintop_thickright_thickbottom_thinleft,	// ╆
	wall_t_thicktop_thickright_thinbottom_thickleft,// ╇
	wall_t_thintop_thickright_thickbottom_thickleft,// ╈
	wall_t_thicktop_thinright_thickbottom_thickleft,// ╉
	wall_t_thicktop_thickright_thickbottom_thinleft,// ╊
	wall_t_thin,					// ┼
	wall_t_double,					// ╬
	wall_t_doubletop_singleright_doubledown_singleleft,// ╫
	wall_t_singletop_doubleright_singledown_doubleleft,// ╪

	t_noleft_thick,					// ┣
	t_noleft_thintop_thickright_thickbottom,	// ┢
	t_nolefft_thicktop_thickright_thinbottom,	// ┡
	t_noleft_thicktop_thinright_thickbottom,	// ┠
	t_noleft_thintop_thinright_thickbottom,		// ┟
	t_noleft_thicktop_thinright_thinbottom,		// ┞
	t_noleft_thintop_thickright_thinbottom,		// ┝
	t_noleft_thing,					// ├

	crossing_slashes,	// ╳
	slash_forward,		// ╱
	slash_back,		// ╲
};


array wall_horizontal {{
	wall_horizontal_thick,                  // ━
        wall_horizontal_thin,                   // ─
        wall_horizontal_thinleft_thickright,    // ╼
        wall_horizontal_thickleft_thinright,    // ╾
        wall_horizontal_thick_left,             // ╸
        wall_horizontal_thick_right,            // ╺
        wall_horizontal_thin_left,              // ╴
        wall_horizontal_thin_right,             // ╶
        wall_horizontal_double,			// ═
	dash,					// -
	underscore,				// _
	equals					// =
}};


/* sixe is 80x20 for now */
#define MAX_COLS 80
#define MAX_ROWS 20

#endif /* STDDEF_HH */
