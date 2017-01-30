#pragma verbose_errors

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Inherits
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
inherit "/room/room";
inherit "/players/darkfire/obj/color";

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Constants
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define UTIL "players/darkfire/obj/util"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Global Variables
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string *smells;
string *sounds;
string *room_chats;
int chat_frequency;
string path; /* The file path to this room. */
string area_name; /* The name of the area containing this room. */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Method Declarations

NOTE: For two methods, add_smell and add_sound, I cannot seem to declare their
type (void) without strange errors occurring. I need to check this out and then
turn on strict_types.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reload();
void construct();
int write_random_array_string(string *arr);
int tell_room_random_array_string(string *arr);
void set_long(string description);
void set_short(string description);
void add_item(string name, string description);
void add_alias(string name, string realitem);
int smell();
add_smell(string smell);
int listen();
add_sound(string sound);
void add_room_chat(string chat);
void room_chat_callout();
void room_chat();
void set_chat_frequency(int frequency);
void set_area_name(string str);
string area_name();
void set_path(string str);
string path();
void add_monster(string path, int copies);
void add_monsters(string *paths);

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Reset initializes the room for the first time (passing in a 0 argument) and
then resets the room from then on (by passing a non-0 argument). This is stupid
and whoever designed this part of the driver should be pummeled with a carrot.

NOTE: I have changed the API here to separate construction of the object from
reloading of the object to help make room code clearer.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reset(int arg) {
	::reset(arg);
	reload();
	if (arg) return;
	room_chat_callout();
	construct();
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This function is called when the driver calls reset at any point, either
during initial object construction or occasionally after that. It is advisable
to override this method and remember to call the superclass ::reload() also.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void reload() {
	/* Do nothing. Override in the inheriting object. */
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
This function is called when the driver calls reset with no arg (or 0), which
happens during initial object construction. It is advisable to override this
function and remember to call the superclass ::construct() also.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void construct() {
	/* Set some default values. */
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Init handles the situation when a player encounters the room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void init() {
	::init();
	add_action("smell", "smell");
	add_action("smell", "sniff");
	add_action("listen", "listen");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Convenience methods for telling the room or writing random strings from an
array that is provided. These are used by the chat/listen/smell commands.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int write_random_array_string(string *arr) {
	if (sizeof(arr) > 0) {
		write(UTIL->get_random_array_member(arr) + "\n");
		return 1;
	}
	return 0;
}

int tell_room_random_array_string(string *arr) {
	if (sizeof(arr) > 0) {
		tell_room(this_object(), UTIL->get_random_array_member(arr) + "\n");
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Override the base room methods to wrap descriptions automatically, but without
affecting the room API.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_long(string description) {
	/* Add a newline otherwise exits come up badly. */
	::set_long(UTIL->wrap(description) + "\n");
}

void set_short(string description) {
	::set_short(UTIL->wrap(description));
}

void add_item(string name, string description) {
	::add_item(name, UTIL->wrap(description));
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Adds an alias from one room item to another.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_alias(string name, string realitem) {
	::add_item(name, "&"+realitem+"&");
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Allows any room that inherits this to easily add a smell.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int smell() {
	return write_random_array_string(smells);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add a new smell to the array of possible smells.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
add_smell(string smell) {
	smells = (string*)UTIL->array_add(smell, smells);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Allows any room that inherits this to easily add a sound.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
int listen() {
	return write_random_array_string(sounds);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add a new sound to the array of possible sounds.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
add_sound(string sound) {
	sounds = (string*)UTIL->array_add(sound, sounds);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Allows any room that inherits this to easily add ambience.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_room_chat(string chat) {
	room_chats = (string*)UTIL->array_add(chat, room_chats);
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Should set a call_out for the room chat. Uses Dragnar's new code to only do
this if a player is present in the room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void room_chat_callout() {
	if (find_call_out("room_chat") == -1) {
		set_call_out("room_chat", chat_frequency);
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Executes the room chat message by picking a random array member to tell.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void room_chat() {
	tell_room_random_array_string(room_chats);
	room_chat_callout();
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Set how often we want room chats to occur.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_chat_frequency(int frequency) {
	chat_frequency = frequency;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Setting the file path to the room makes it a little less cluttered when we
add obvious exits or hidden exits, since we only refer to the full path once.
This also makes changing paths a lot easier, and really works for gridroom.c
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_path(string str) {
	path = str;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Return the path to this room. Use like: add_exit(path() + "a1", "west");
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string path() {
    return path;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Setting an area name lets every room in that area use it easily for things
like chats, signs, descriptions, etc.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void set_area_name(string str) {
	area_name = str;
}

string area_name() {
	return area_name;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add a specific monster to a room (potentially with multiple copies).
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_monster(string path, int copies) {
    int i;

    for (i = 0; i < copies; i++) {
        move_object(clone_object(path), this_object());
    }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add a specific monster to a room, but only if the "key" isn't present.
Presumably the key is the ID of the monster, but could be something else.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_monster_if_not_present(string key, string path, int copies) {
    int i;

    if (!present(key)) {
	    for (i = 0; i < copies; i++) {
	        move_object(clone_object(path), this_object());
	    }
    }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add an entire list of monsters to a room.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_monsters(string *paths) {
	int i;

	for (i = 0; i < sizeof(paths); i++) {
		move_object(clone_object(paths[i]), this_object());
	}
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Add a list of monsters to a room, if they "key" is not present. This relies
on the order of the keys being the same as the order of the paths.

NOTE: This would be better done as a map, but I haven't had much luck with
maps on this driver so I'm going to leave that for later. Specifically, I
can't seem to retrieve an object by its key without converting both to arrays.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
void add_monsters_if_not_present(string *keys, string *paths) {
	int i;

	for (i = 0; i < sizeof(paths); i++) {
		if (!present(keys[i])) {
			move_object(clone_object(paths[i]), this_object());
		}
	}
}
