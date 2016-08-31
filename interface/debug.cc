#include <iostream>
#include <string>
#include "stddef.hh"
#include "stdlib.hh"

/* A simple library for debugging purposes, or until we can get a proper
 * curses/ncurses one working.
 */


class DebugDisplayer {

// Just so the public stuff is less indented
public:
	// If the interface has more options to add, like IBMgraphics
	bool hasmoreconfig = false;

	// What it would look like if such were true
	/* std::vector<std::vector<interfaceconf>> {{
	 * 	{{ "ibmgraphics", "bool", false }}
	 * 	{{ "msgtype", "multiple", nullptr }}
	 * 	{{ "symset", "string", "ascii" }}
	 * }}
	 *
	 * Everything has a default value.  For multiple & symset, nullptr
	 * means it's not set.
	 *
	 * You can have:
	 *	"bool," can be true or false.  Requires a default value.
	 *	"multiple," multiple comma-seperated rules.  Returns a vector
	 *		    of all of them, in std::string format.
	 *	"string," a simple string of form std::string.
	 */
} debugdisplay;
