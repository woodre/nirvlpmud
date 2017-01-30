#pragma strict_types

#include <ansi.h>
#include "/players/darkfire/castle/circus/circus.h"

inherit "/players/darkfire/obj/gridroom";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
mapping room_items;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_items(mapping map);
void add_items(string description);
void add_room_monsters();

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Initial construction of the room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void construct() {
	::construct();
    set_light(1);
    set_short(AREA_NAME);
    add_smell("The faint odor of rotten fruit pervades the area.");
    add_sound("You can faintly hear the moaning of the wind blowing through the trees.");
    add_room_chat("A low rumbling can be felt more than heard as the entire park shudders.");
    set_chat_frequency(120);
    set_path(PATH_ROOMS);
    set_area_name(AREA_NAME);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Reloading the room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reload() {
	::reload();
	call_out("add_room_monsters", 1);
}

void set_items(mapping map) {
    room_items = map;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This automatically places a header and footer around the room's description,
with the short desc (area name) centered and bracketed in bright white.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_long(string description) {
    string header, footer;
    header = (string)UTIL->cpad(hiw(" [ ") + query_short() + hiw(" ] "), 70, "-=");
    footer = (string)UTIL->lpad("", 70, "-=");
    ::set_long(header + "\n" + UTIL->wrap(description) + "\n" + footer + "\n");
    add_items(description);
}

void add_items(string description) {
    int i;
    if (!room_items) return;

    for (i = 0; i < sizeof(m_indices(room_items)); i++) {
/* TODO: Make this only add the items that are contained in the room description.
        if (sscanf(remove_color(description), "%s", m_indices(room_items)[i]) > 0) {*/
        add_item(m_indices(room_items)[i], m_values(room_items)[i]);
    }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Every room has a chance to get a scavenging animal added to it. Since they
wander, over time this will lead to quite a few scavengers in the area if
nobody kills them. At a certain population, though, the chances of new ones
should decrease sharply since there will be at least one in every room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_room_monsters() {
	if (!present("scavenger")) {
		add_monsters(UTIL->get_random_array_members(SCAVENGERS, random(2)));
	}
}
