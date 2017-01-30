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

	set_short(MIDWAY);
	add_smell("You smell the delicious odor of deep fried Oreos.");
	add_smell("The square smells of old cotton candy and rusty metal.");
	add_sound("The wind makes an eerie noise as it blows through the old tents and rides.");
	add_sound("You can hear muted bells, whistles, and cheers as a ghostly crowd enjoys the midway games.");
	add_room_chat("The sound of rusty metal shrieks in the distance.");
	add_room_chat("The haunting voice of a long dead carnival barker whispers down the midway.");
	set_path(PATH_MIDWAY);
	set_area_name(MIDWAY);
	set_cols(COLS);
	set_rows(ROWS);
}

void add_room_monsters() {
	::add_room_monsters();
	if (!present("ghost")) {
		add_monsters(UTIL->get_random_array_members(GHOSTS, (random(10) == 0)));
	}
	if (!present("toy")) {
		add_monsters(UTIL->get_random_array_members(TOYS, random(2)));
	}
}
