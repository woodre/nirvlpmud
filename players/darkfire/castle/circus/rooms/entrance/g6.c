#pragma strict_types

/* =-=-=-=-=-=-=-=-=-=-=-=-=-
 8X8 Chess Board Layout
  -------------------
8 | + + + + + + + + |
7 | + + + + + + + + |   ^
6 | X + + + + + + + |  /+\
5 | + + + + + + + + |   +
4 | + + + + + + + + |   +
3 | + + + + + + + + | North
2 | + + + + + + + + |
1 | + + + + + + + + |
  ------------------/
    A B C D E F G H
=-=-=-=-=-=-=-=-=-=-=-=-=- */

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area's base room. */
inherit "/players/darkfire/castle/circus/rooms/entrance/_base.c";

void
reset(int arg) {
	int col, row;
	if(arg) return;
	::reset();

	col = 6;
	row = 5;

	set_default_long(col, row);
	add_default_exits(col, row);
}

void
init() {
	::init();
}
