#include <cstdio>
#include <string>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"
#include "tile.hh"

// we're doing it dumbly, using str concatenation
// the parser doesn't have that privelege, unfortunately

// ex:
/* {
 * 	is_gamemap: true,
 * 	gamemap: [
 * "", [ [start, end, r, g, b], &c],
 * "", [ [start, end, r, g, b], &c],
 * [... (however many lines)]
 * 	],
 * 	inventory: [
 * 	[same as gamemap]
 * 	],
 *
 * 	havemsg: true,
 * 	msg: "The lichen hits!",
 * 	msgcolours = [ [start, end, r, g, b], &c],
 * 	
 * 	hp: 5,
 * 	maxhp: 7,
 * 	mp: 3,
 * 	maxhp: 5,
 * }
 */

// animation ex:
/* {
 * 	isgamemap: false,
 * 	x1: 5,
 * 	y1: 10,
 * 	x2: 5,
 * 	y2: 15,
 * 	colour = [r, g, b]
 * 	animation_type: "beam"
 * }
 */

// just returns the colour part, doesn't worry about the str part
str JSONDisplayer::rgbstr2json(ColouredString rgbstring) {
	str currstring = "[";
	for (ColourSpec spec: rgbstring.colourlist) {
		currstring += "\"" + std::to_string(spec.start) + "\", ";
		currstring += "\"" + std::to_string(spec.end) + "\", ";
		currstring += "\"" + std::to_string(spec.colour.r) + "\", ";
		currstring += "\"" + std::to_string(spec.colour.g) + "\", ";
		currstring += "\"" + std::to_string(spec.colour.b) + "\"]";
	}
	return currstring;
}
void JSONDisplayer::refresh(GameMap& map) {
	printf("{ \"is_gamemap\": true, \"gamemap\": [");
	for (ColouredGlyphString line: map.mapspace) {
		printf("\"");
		for (Glyph glyph: line.somestr)
			printf("%s", tileset()[glyph].c_str());
		printf("\",");
	}
	printf("], \"inventory\": [");
	for (ColouredString line: map.inventory) {
		printf("\"%s\", %s, ", line.somestr.c_str(), rgbstr2json(line).c_str());
	}

	printf("], \"havemsg\": ");
	if (map.havemsg) {
		printf("true, \"msg\": \"%s\", \"msgcolours\": %s", map.msg.somestr.c_str(), rgbstr2json(map.msg).c_str());
	} else {
		printf("false");
	}

	printf(", \"hp\": %d", map.hp);
	printf(", \"maxhp\": %d", map.maxhp);
	printf(", \"mp\": %d", map.mp);
	printf(", \"maxmp\": %d", map.maxmp);
	printf("}");
}

void JSONDisplayer::animation_sparkle(short x, short y) {
	str currstring = "{ \"is_gamemap\": false, \"animation_type\": \"beam\", ";
	currstring += "\"x\": " + std::to_string(x) + ", ";
	currstring += "\"y\": " + std::to_string(y);
	currstring += "}";
}

char JSONDisplayer::readchar() {
	return getchar();
}

void JSONDisplayer::start() {}
void JSONDisplayer::end() {}
