#pragma strict_types

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/players/darkfire/castle/circus/rooms/_circus.c";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"
#include "_area.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string get_graveyard_description();
void add_room_monsters();
void add_tombstone();
void reload();
void construct();

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

	set_short(NAME_GRAVEYARD);
	add_smell("You smell freshly turned earth.");
	add_sound("You can hear muted growls and yelps from beneath your feet.");
	add_room_chat("The bones hanging from the magnolia tree rattle in the wind.");
	set_path(PATH_GRAVEYARD);
	set_area_name(NAME_GRAVEYARD);
	set_cols(COLS);
	set_rows(ROWS);
	set_chat_frequency(1);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Thes rooms are described randomly when they are created. This is done
by having an array of sentences to choose from, then randomly grouping them
together. Each reboot, the rooms will change slightly. It's also very easy to
add variety by simply adding more sentences later. Constant sentences can be
added before or after the random section, or even intermingled if you use two
random calls (though then you might get duplicate lines).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string get_graveyard_description() {
	mixed *lines;
	lines = (mixed *)UTIL->get_random_array_members(DESCS_GRAVEYARD, random(2) + 2);

	return "You step through the deep grass of the graveyard, "
		+ "always keeping a wary eye on the tree in the center. "
		+ implode(lines, " ");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Every room has a chance to get a scavenging animal added to it. Since they
wander, over time this will lead to quite a few scavengers in the area if
nobody kills them. At a certain population, though, the chances of new ones
should decrease sharply since there will be at least one in every room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_room_monsters() {
	::add_room_monsters();
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This function adds a tombstone to the room. It's defined here, but not called
since we don't want tombstones in every room, just most of them.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_tombstone() {
	object grave;

	/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	Only add a tombstone if there aren't tombstones or ghouls already there.
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
	if (!present("tombstone") && !present("ghoul")) {
		move_object(clone_object(ITEM_MISC_TOMBSTONE), this_object());

		/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		If a tombstone previously created an open grave, get rid of it.
		=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
		grave = present("grave");

		if (grave) {
			destruct(grave);
		}
	}
}
