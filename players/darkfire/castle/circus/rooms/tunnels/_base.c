#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area base room. */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

/* Then inherit the room that lets this room act like part of a grid. */
inherit "/players/darkfire/obj/gridroom";

#define UTIL "players/darkfire/obj/util"

string get_random_description();
void set_long_intersection();

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

	set_short(NAME_TUNNELS);
	add_smell("You smell the acrid stench of toxic waste.");
	add_sound("You can hear the sound of water dripping into a pool.");
	add_room_chat("A long moan fills the tunnels as a breeze slips in through a gap somewhere in the walls.");
	set_path(PATH_TUNNELS);
	set_area_name(NAME_TUNNELS);
	set_cols(COLS);
	set_rows(ROWS);
}

void set_long_intersection() {
	set_long(DESC_INTERSECTION + " " + get_random_description());
}

void set_long_alcove() {
	set_long(DESC_ALCOVE + " " + get_random_description());
}

void set_long_tunnel() {
	set_long(DESC_TUNNEL + " " + get_random_description());
}

void set_long_deadend() {
	set_long(DESC_DEADEND + " " + get_random_description());
}

void set_long_bend() {
	set_long(DESC_BEND + " " + get_random_description());
}

string get_random_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS, random(2) + 2);
	return implode(lines, " ");
}

void add_room_monsters() {
	::add_room_monsters();
	if (!present("mutant")) {
		add_monsters(UTIL->get_random_array_members(MUTANTS, random(2)));
	}
}
