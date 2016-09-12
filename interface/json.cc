#include <iostream>
#include <string>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"

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
	cout << "{ \"is_gamemap\": true, \"gamemap\": [";
	for (ColouredString line: map.mapspace) {
		cout << "\":wq

		currstring += "\"" + line.somestr + "\", " + rgbstr2json(line) + ", ";
	}
	currstring += "], \"inventory\": [";
	for (ColouredString line: map.inventory) {
		currstring += "\"" + line.somestr + "\", " + rgbstr2json(line) + ", ";
	}

	currstring += "], \"havemsg\": ";
	currstring += map.havemsg ? "true, \"msg\": \"" + map.msg.somestr + "\", \"msgcolors\": " + rgbstr2json(map.msg) : "false";

	currstring += ", \"hp\": " + std::to_string(map.hp);
	currstring += ", \"maxhp\": " + std::to_string(map.maxhp);
	currstring += ", \"mp\": " + std::to_string(map.mp);
	currstring += ", \"maxmp\": " + std::to_string(map.maxmp);
	currstring += "}";
	std::cout << currstring;
}

void JSONDisplayer::animation_sparkle(short x, short y) {
	str currstring = "{ \"is_gamemap\": false, \"animation_type\": \"beam\", ";
	currstring += "\"x\": " + std::to_string(x) + ", ";
	currstring += "\"y\": " + std::to_string(y);
	currstring += "}";
}

char JSONDisplayer::getchar() {
	char foo;
	std::cin >> foo;
	return foo;
}
