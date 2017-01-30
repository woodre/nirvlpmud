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

	set_short(NAME_TRAIN);
	add_smell("You smell the moldering remains of dead hobos.");
	add_sound("The faint sound of a train whistle echoes eerily through the hills.");
	add_room_chat("You hear the scrabbling of claws on rusty iron.");
	set_path(PATH_TRAIN);
	set_area_name(NAME_TRAIN);
	set_cols(COLS);
	set_rows(ROWS);
	set_items(ITEMS);
}

string get_train_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_TRAIN, random(2) + 2);
	return "You are in a boxcar sitting on train tracks nearly reclaimed by the surrounding forest. " + implode(lines, " ");
}

string get_path1_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_PATH1, random(2) + 2);
	return "You are walking along a narrow, winding dirt track through a dense forest. " + implode(lines, " ");
}

string get_path2_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_PATH2, random(2) + 2);
	return "You are on a narrow path running between a thick forest to the west, and a line of train cars to the east. " + implode(lines, " ");
}

void add_room_monsters() {
	::add_room_monsters();
	if (!present("ghost")) {
		add_monsters(UTIL->get_random_array_members(GHOSTS, random(2)));
	}
}

