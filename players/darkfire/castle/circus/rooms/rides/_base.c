#pragma strict_types

#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* Inherit the area base room. */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

/* Then inherit the room that lets this room act like part of a grid. */
inherit "/players/darkfire/obj/gridroom";

/* Function declarations. */
string get_coaster_description();
string get_carousel_description();
string get_mine_description();
string get_funhouse_description();

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
	add_smell("You smell old sawdust and vomit.");
	add_sound("The old wooden roller coaster creaks in the distance.");
	add_room_chat("Dead leaves swirl in a gust of wind, then settle back to the dirt.");
	set_path(PATH_RIDES);
	set_area_name("Amusement Park Rides");
	set_cols(COLS);
	set_rows(ROWS);
}

string get_coaster_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_COASTER, random(2) + 2);
	return "You're walking along the tracks of the abandoned wooden roller coaster. " + implode(lines, " ");
}

string get_carousel_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_CAROUSEL, random(1) + 2);
	return "You're on the wobbly platform surrounded by giant wooden animals mounted on poles. " + implode(lines, " ");
}

string get_mine_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_MINE, random(2) + 2);
	return "You're deep in the tunnels of an abandoned mine cart ride. " + implode(lines, " ");
}

string get_funhouse_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_FUNHOUSE, random(1) + 2);
	return "You're stumbling through the halls of a delapidated fun house. " + implode(lines, " ");
}

string get_path_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_PATH, random(1) + 2);
	return "Everything is eerily quiet along the " + PATH_NAME + " through the amusement park rides. " + implode(lines, " ");
}

void add_room_monsters() {
	::add_room_monsters();
	if (!present("ghost")) {
		add_monsters(UTIL->get_random_array_members(GHOSTS, random(2)));
	}

	add_monster_if_not_present("ghost", UTIL->get_random_array_members(GHOSTS, 1), random(1));
}
