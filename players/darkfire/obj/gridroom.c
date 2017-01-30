#pragma strict_types

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This is a room that can act as if it's a member of a grid by assuming the file
names of the surrounding rooms. It infers these file names based on two arrays,
columns and rows. Depending on the length of each of those arrays, adding exits
to this room will correctly link to the other rooms in the area, or the exit
addition will fail if it knows it's at the limit of either the rows or columns.

This uses 8X8 Chess Board Layout as its basic grid, but can be expanded to any
rectangular shape of rows X cols.

  -------------------
8 | + + + + + + + + |
7 | + + + + + + + + |   ^
6 | + + + + + + + + |  /+\
5 | + + + + + + + + |   +
4 | + + + + + + + + |   +
3 | + + + + + + + + | North
2 | + + + + + + + + |
1 | + + + + + + + + |
  ------------------/
    A B C D E F G H
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/players/darkfire/obj/dfroom";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string *cols;
string *rows;
int col;
int row;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_default_exits();
void add_exits(string exitlist);
void add_south_exit();
void add_north_exit();
void add_west_exit();
void add_east_exit();
void add_southeast_exit();
void add_northeast_exit();
void add_southwest_exit();
void add_northwest_exit();
void set_default_long();
void set_row(int arg);
void set_col(int arg);
void set_rows(string *arg);
void set_cols(string *arg);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Basic setters so the rooms that inherit this can 'participate' in the grid by
declaring their position within it and providing the bounding arrays.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_row(int arg) {
	row = arg;
}

void set_col(int arg) {
	col = arg;
}

void set_rows(string *arg) {
	rows = arg;
}

void set_cols(string *arg) {
	cols = arg;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add the exits, if the bounds of cols/rows and the room's position allows it.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_south_exit() {
	/* Do not add south exits to southernmost rooms. */
	if (row > 0) {
		add_exit(path() + cols[col] + rows[row-1] , "south");
	}
}

void add_north_exit() {
	/* Do not add north exits to northernmost rooms. */
	if (row < sizeof(rows)-1) {
		add_exit(path() + cols[col] + rows[row+1] , "north");
	}
}

void add_west_exit() {
	/* Do not add west exits to westernmost rooms. */
	if (col > 0) {
		add_exit(path() + cols[col-1] + rows[row], "west");
	}
}

void add_east_exit() {
	/* Do not add east exits to easternmost rooms. */
	if (col < sizeof(cols)-1) {
		add_exit(path() + cols[col+1] + rows[row], "east");
	}
}

void add_southeast_exit() {
	/* Do not add south exits to southernmost rooms. */
	/* Do not add east exits to easternmost rooms. */
	if (row > 0 && col < sizeof(cols)-1) {
		add_exit(path() + cols[col+1] + rows[row-1] , "southeast");
	}
}

void add_southwest_exit() {
	/* Do not add south exits to southernmost rooms. */
	/* Do not add west exits to westernmost rooms. */
	if (row > 0 && col > 0) {
		add_exit(path() + cols[col-1] + rows[row-1] , "southwest");
	}
}

void add_northeast_exit() {
	/* Do not add north exits to northernmost rooms. */
	/* Do not add east exits to easternmost rooms. */
	if (row < sizeof(rows)-1 && col < sizeof(cols)-1) {
		add_exit(path() + cols[col+1] + rows[row+1] , "northeast");
	}
}

void add_northwest_exit() {
	/* Do not add north exits to northernmost rooms. */
	/* Do not add west exits to westernmost rooms. */
	if (row < sizeof(rows)-1 && col > 0) {
		add_exit(path() + cols[col-1] + rows[row+1] , "northwest");
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Parses a comma-delimited string into an array and determines which exits to
add to the room based on those. Nice and easy to do: add_exits("n,s");
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_exits(string exitlist) {
	string *exits;
	exits = explode(exitlist, ",");

	if (member_array("n", exits) > -1) {
		add_north_exit();
	}
	if (member_array("s", exits) > -1) {
		add_south_exit();
	}
	if (member_array("e", exits) > -1) {
		add_east_exit();
	}
	if (member_array("w", exits) > -1) {
		add_west_exit();
	}
	if (member_array("ne", exits) > -1) {
		add_northeast_exit();
	}
	if (member_array("se", exits) > -1) {
		add_southeast_exit();
	}
	if (member_array("nw", exits) > -1) {
		add_northwest_exit();
	}
	if (member_array("sw", exits) > -1) {
		add_southwest_exit();
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Just adds the primary 4 exits to a room, but if you wanted to default in some
other way you could (e.g. make a huge hallway by defaulting to just w,e).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_default_exits() {
	add_exits("n,s,e,w");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
While you're constructing an area, this can be handy to help visualize the
area as it's being built. Just call this in each of the grid rooms and you'll
know exactly where you are. Good for comparing to hand-drawn sketches, too.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_default_long() {
	/* Set the long description (displayed when someone looks at the room). */
	set_long(hiw(area_name()) + " Room " + hiw(cols[col] + rows[row])
		+ " (chess grid notation) \n"
		+ "There are hammers and saws and raw lumber laying everywhere, "
		+ "along with a big sign that says '" + hir("UNDER CONSTRUCTION") + "'."
	);
}
