#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area base room. */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

/* Then inherit the room that lets this room act like part of a grid. */
inherit "/players/darkfire/obj/gridroom";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Called when the room is reloaded by the driver.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reload() {
	::reload();

	/* This is a call_out so that wandering monsters work (actually wander). */
	call_out("add_room_monsters", 1);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Called when the room is initially created by the driver.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void construct() {
	::construct();
	set_short(AREA_NAME + " " + ABANDONED);
	add_smell("You smell wet moss and moldy leaves.");
	add_sound("The wind makes an eerie noise as it blows through the old tents and rides.");
	add_room_chat("The sound of fluttering canvas echoes through the trees.");
	set_path(PATH_TENTS);
	set_area_name(AREA_NAME + " " + ABANDONED);
	set_cols(COLS);
	set_rows(ROWS);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Creates a description of the path through the tents by grouping random lines.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string get_path_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_PATH, random(2) + 2);
	return "You walk along " + PATH_NAME + ". " + implode(lines, " ");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Creates a description of the tents by grouping random lines.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string get_tent_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_TENT, random(2) + 2);
	return TENT_NAME + ". " + implode(lines, " ");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add some ghosts to the rooms.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_room_monsters() {
	::add_room_monsters();
	if (!present("ghost")) {
		add_monsters(UTIL->get_random_array_members(GHOSTS, random(2)));
	}
}

