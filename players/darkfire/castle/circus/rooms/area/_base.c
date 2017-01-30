#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"


/* Inherit the area base room. */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

string area_name();
void add_default_exits(int row, int col);

void
reset(int arg) {
	if(arg) return;
	::reset();

	/* Set the long description (displayed when someone looks at the room). */
	set_long("A room in the " + area_name() + ".");

	/* Add smells to the room. */
	add_smell("A new random smell just for the " + area_name() + " area.");

	/* Add sounds to the room. */
	add_sound("A new random sound just for the " + area_name() + " area.");

	/* Add ambient room chats. */
	add_room_chat("A new random ambient room chat just for the " + area_name() + " area.");
}

void
init() {
	::init();
}

void
add_south_exit(int col, int row) {
	add_exit(path() + COLS[col] + ROWS[row-1] , "south");
}

void
add_north_exit(int col, int row) {
	add_exit(path() + COLS[col] + ROWS[row+1] , "north");
}

void
add_west_exit(int col, int row) {
	add_exit(path() + COLS[col-1] + ROWS[row], "west");
}

void
add_east_exit(int col, int row) {
	add_exit(path() + COLS[col+1] + ROWS[row], "east");
}

void 
add_default_exits(int col, int row) {
	/* North and south, except in the northernmost/southernmost rooms. */
	if (row > 0) {
		add_south_exit(col, row);
	}
	if (row < sizeof(ROWS)-1) {
		add_north_exit(col, row);
	}

	/* West and east, except in the westernmost/easternmost rooms. */
	if (col > 0) {
		add_west_exit(col, row);
	}
	if (col < sizeof(COLS)-1) {
		add_east_exit(col, row);
	}
}

void
set_default_long(int col, int row) {
	/* Set the long description (displayed when someone looks at the room). */
	set_long(hiw(area_name()) + " Room " + hiw(COLS[col] + ROWS[row]) + " (chess grid notation) \n"
		+ "There are hammers and saws and raw lumber laying everywhere, "
		+ "along with a big sign that says '" + hir("UNDER CONSTRUCTION") + "'."
	);
}

string 
path() {
	return PATH_AREA;
}

string
area_name() {
	return "Generic";
}
