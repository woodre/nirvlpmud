/*
 * Scents/sounds/.. Balowski@Nirvana
 */
#include "/players/guilds/bards/bard_lib/lib.h"
#pragma strict_types
#pragma save_types
private mixed	Scents, Sounds, Search;

void create()
{
}

status id(string str)
{
}

status cmd_search(string str)
{
    string s;
    if (!str) {
	if (stringp(Search)) s = Search;
	else if (mappingp(Search)) s = Search["default"];
    } else {
	if (mappingp(Search)) s = Search[str];
    }
    /*if (!s) return (notify_fail("Search what?\n"), 0);*/
    if (closurep(s)) s = funcall(s, str);
    if (!s) return (notify_fail("You find nothing special.\n"), 0);
    if (stringp(s)) write(s);
    say(this_player()->query_name() + " searches the " +
	(str ? str + ".\n" : "surroundings.\n"));
    return 1;
}

status cmd_listen(string str)
{
    string s;

    if (!mappingp(Sounds) || !(s = Sounds["dominant"])) {
	if (!str) {
	    s = mappingp(Sounds) ? Sounds["default"] : Sounds;
	} else {
	    /* what kind of syntax do we want here? just 'listen to <x>'?*/
	    if (sscanf(str, "to %s", s)) str = s;
	    if (mappingp(Sounds)) s = Sounds[str]; else s = 0;
	}
    }
    /*if (!s) return (notify_fail("Listen to what?\n"), 0);*/
    if (closurep(s)) s = funcall(s, str);
    if (!s) return (notify_fail("You hear nothing special.\n"), 0);
    if (stringp(s)) write(s);
    say(this_player()->query_name() + " pricks up " +
	possessive(this_player()) + " ears.\n");
    return 1;
}

status cmd_smell(string str)
{
    string s;
    if (!mappingp(Scents) || !(s = Scents["dominant"])) {
	if (!str) {
	    if (stringp(Scents)) s = Scents;
	    else if (mappingp(Scents)) s = Scents["default"];
	} else {
	    if (mappingp(Scents)) s = Scents[str];
	}
    }
    /*if (!s) return (notify_fail("Smell what?\n"), 0);*/
    if (closurep(s)) s = funcall(s, str);
    if (!s) return (notify_fail("You notice no special odours.\n"), 0);
    if (stringp(s)) write(s);
    say(this_player()->query_name() + "'s nostrils flare.\n");
    return 1;
}

void init()
{
    add_action("cmd_listen", "listen");
    add_action("cmd_smell", "smell");
    add_action("cmd_search", "search");
}

void add_smell(string id, mixed s) {
    if (mappingp(Scents)) Scents[id] = s;
    /*else if (stringp(Scents)) Scents = ([ id:s, "default":Scents, ]);*/
    else Scents = ([ id:s, ]);
}
void add_sound(string id, mixed s) {
    if (mappingp(Sounds)) Sounds[id] = s;
    else Sounds = ([id:s]);
}
void add_search(string id, mixed s) {
    if (mappingp(Search)) Search[id] = s;
    else Search = ([id:s]);
}
void set_smells(mapping m) { Scents = copy_mapping(m);}
void set_sounds(mapping m) { Sounds = copy_mapping(m);}
void set_searchs(mapping m) { Search = copy_mapping(m);}
mixed query_smell(string id) { return (Scents && Scents[id]);}
mixed query_sound(string id) { return (Sounds && Sounds[id]);}
mixed query_search(string id) { return (Search && Search[id]);}
