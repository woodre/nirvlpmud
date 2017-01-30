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
inherit "/players/darkfire/castle/circus/rooms/tunnels/_base.c";

void
reset(int arg) {
	int col, row;
	if(arg) return;
	::reset();

	set_col(7);
	set_row(5);

	set_long_bend();

	add_exits("s,w");
}

void
init() {
	::init();
}
