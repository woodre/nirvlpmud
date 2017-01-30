/*
 * Room thingy for 3.1.2-DR, Nirvana
 * Inspired by Foundation/Nightmare..
 */
#include "/players/balowski/lib.h"
#pragma strict_types
#pragma save_types
inherit BASE;

#undef SPARRING                 /* needed 1 out of 10000 */

private string  RoomShort;      /* brief description */
private string  RoomLong;       /* Long description of the room */
private mapping Exits;          /* of format direction:file */
private mapping Items;          /* lookables */
private mapping Signs;          /* things to read */
private mixed	Scents, Sounds, Search;
private mapping Props;          /* properties like "mo nagic" :^) */
				/* "no teleport"/"fight area"/"spar area" */
private int     MaxCastles;     /* allow castle drop? */
private status  NoClean;        /* set to stop self destruct on idle */
private string	*Chats;
private int	ChatFreq, Players;


void
create()
{
    Exits = ([ ]);
    Items = ([ ]);
    Props = ([ ]);
    Signs = ([ ]);
}

status
id(string str)
{
    return (Items[str] || Signs[str]);
}

string
short()
{
    if (set_light(0))
	return RoomShort;
    return "Dark room";
}

/*
 * Somewhat against my religion, but - hohum - here we go
 */
status
cmd_read(string str)
{
    string s;

    if (!str || !(s = Signs[str])) {
	notify_fail("Read what?\n");
	return 0;
    }
    if (closurep(s))
	s = funcall(s, str);
    if (stringp(s)) {
	if (s[0] == '/')
	    cat(s);
	else
	    write(s);
    }
    say(this_player()->query_name() + " reads the " + str + ".\n");
    return 1;
}

status
cmd_search(string str)
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

status
cmd_listen(string str)
{
    string s;

    if (!mappingp(Sounds) || !(s = Sounds["dominant"])) {
	if (!str) {
	    if (stringp(Sounds)) s = Sounds;
	    else if (mappingp(Sounds)) s = Sounds["default"];
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

status
cmd_smell(string str)
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

/*
 * cmd_move (for old times sake it is named move)
 */
status
move(string str)
{
    mixed       exit;

    if (exit = Exits[query_verb()]) {
	if (closurep(exit))
	    exit = funcall(exit, str);
	else if (objectp(exit))
	    exit = (mixed) call_other(exit, query_verb(), str);
	if (intp(exit))
	    return exit;
	if (stringp(exit))
	    this_player()->move_player(query_verb() + "#" + exit);
	return 1;
    }
    notify_fail("You cannot go that way.\n");
    return 0;
}

/*
 * Multi purpose function used by the mudlib
 * Called with no arg whenever player does 'look'
 * Called with <x>, if player does 'look at <x>' and id(<x>) returns true
 */
void
long(string str)
{
    string s;

    if (!set_light(0))
       write("It is dark.\n");
    else {
	if (str) {
	    if (s = Items[str]) {
		if (closurep(s)) s = funcall(s, str);
		if (stringp(s)) write(s);
	    }
	    else if (Signs[str])
		/*write("You should read it.\n");*/
		cmd_read(str);
	}
	else {
	    s = RoomLong;
	    if (closurep(s)) s = funcall(s, 0);
	    if (stringp(s)) write(s);
	}
    }
}

/*
 * Applied by the driver whenever a living creature enters
 */
void
init()
{
    int         i;
    mixed       *ks;

#ifdef SPARRING
    if (this_player()->is_player() && (int) this_player()->query_pl_k() < 2) {
	this_player()->move_player("X#/room/void");
    }
#endif

    if (Props["fight area"])
	this_player()->set_fight_area();
    Players += (int) this_player()->is_player(); /* assumed to be 1 or 0 */
    if (ChatFreq && Players == 1)
      call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));

    /* shiver! */
    add_action("cmd_read", "read");
    add_action("cmd_listen", "listen");
    add_action("cmd_smell", "smell");
    add_action("cmd_search", "search");

    /* okay, so this isn't pretty.. can't have it all */
    i = sizeof(ks = m_indices(Exits));
    while (i--)
	add_action("move", ks[i]);
}

/*
 * Here goes some of the Nirvana oddities.
 * The realm function should be checked before teleporting players
 * If query_spar_area returns non-zero, players don't lose xp on death
 * The fight area thing allows for pk fights
 */
string
realm()
{
    return (Props["no teleport"] ? "NT" : (Props["no follow"] ? "LA" : 0));
}

#ifdef SPARRING
mixed
query_spar_area()
{
    return (Props["spar area"]);
}
#endif

/*
 * Applied by the driver whenever an object if removed from here
 */
void
exit(object ob)
{
    if (living(ob) && ob->is_player()) {
	if (!--Players) remove_call_out("ev_chat");
	if (Props && Props["fight area"])
	    ob->clear_fight_area();     /* not really necessary.. */
#ifdef SPARRING
	if (Props && Props["spar area"])
	    ob->rm_spar();              /* removes sparring flag, if set */
#endif
    }
}

/*
 * The long description of the room,
 * The command look should show this
 */
void
set_long(mixed str)
{
    RoomLong = str;
}

string
query_long()
{
    return RoomLong;
}

/*
 * Room exits, this sucks a little *shrug*
 * Adding and removing exits can be done though, just don't like it
 */
void
set_exits(mapping m)
{
    Exits += m;
}

void
set_exit(string dir, mixed whereto)
{
    Exits[dir] = whereto;
}

mapping
query_exits()
{
    return Exits;
}

/*
 * Items to look at .. more or less pinched from foundation
 * piffed up a little, but I don't like all these if's and while's
 * Changable on the fly!
 */
void
add_item(mixed id, string desc)
{
    int         j;

    if (pointerp(id)) {
	j = sizeof(id);
	while (j--)
	    Items[id[j]] = desc;
    }
    else
	Items[id] = desc;
}

void
set_items(mapping m)
{
    int         i, j;
    mixed       *ks;

    i = sizeof(ks = m_indices(m));
    while (i--)
	add_item(ks[i], m[ks[i]]);
}

void
remove_item(mixed id)
{
    int         j;

    if (pointerp( id)) {
	j = sizeof( id);
	while (j--)
	    m_delete(Items, id[j]);
    }
    else
	m_delete(Items, id);
}

/*
 * Things to read (signs)
 * Very simple yet
 */
void
set_sign(string id, mixed txt)
{
    if (!Signs)
	Signs = ([ id:txt ]);
    else
	Signs[id] = txt;
}

void set_smell(mixed s) { Scents = s;}
void set_sound(mixed s) { Sounds = s;}
void set_search(mixed s) { Search = s;}
void set_smells(mapping m) { 
#ifndef __LDMUD__
  Scents = copy_mapping(m);
#else
  Scents = copy(m);
#endif
}
void set_sounds(mapping m) { 
#ifndef __LDMUD__
  Sounds = copy_mapping(m);
#else
  Sounds = copy(m);
#endif
}
void set_searchs(mapping m) { 
#ifndef __LDMUD__
  Search = copy_mapping(m);
#else
  Search = copy(m);
#endif
}
/*
 * Special properties of the room
 * For instance set "no magic" to 1
 */
mixed
query_property(string p)
{
    return Props[p];
}

void
add_property(string p, mixed v)
{
    Props[p] += v;
}

void
set_property(string p, mixed v)
{
    Props[p] = v;
}

void
set_properties(mapping m)
{
    Props += m;
}

/*
 * The short description of the room should be one line,
 * without newline. It is for players with brief set on
 */
void
set_short(string s)
{
    RoomShort = s;
}

string
query_short()
{
    return RoomShort;
}

/*
 * This determines if wizard can drop castles here
 * default is 0, which means not allowed
 */
void
set_max_castles(int value)
{
    MaxCastles = value;
}

int
query_drop_castle()
{
    return MaxCastles;
}

void
set_no_clean(status stop)
{
    NoClean = stop;
}

/*
 * This baby needs work
 * It isn't called often though
 */
int
clean_up(int refcount)
{
    object ob;

    if (NoClean)
	return 0;       /* never again */
    if (refcount)       /* expected to be zero (no clones) */
	return 1;       /* try later */
/*
    if (sizeof(users() & all_inventory()))
	return 1;
*/
    destruct(this_object());
}

/*
 * Funky utility functions
 * MakeNoise will send a message to nearby rooms
 */
varargs int
MakeNoise(mixed msg, mixed exit, status load)
{
    int         i;
    mixed       *ks;
    object      ob;
    string      x;

    i = sizeof(ks = m_indices(Exits));
    while (i--) {
	if (stringp(exit) && ks[i] != exit) continue;
	if (pointerp(exit) && member_array(ks[i], exit) < 0) continue;
	if (stringp(x = Exits[ks[i]])) {
	    if (load) call_other(x, "");
	    if (ob = find_object(x)) tell_room(ob, msg);
	}
    }
}

/*
 * Chat stuff.. quite like monsters
 */
void
load_chats(string *strs)
{
    if (!Chats)	Chats = strs;
    else Chats += strs;
}

void load_chat(string str) { load_chats(({ str }));}

/*
 * Remove a previously loaded chat string.
 * First occurrence matching 'str' will be removed from array
 */
void
remove_chat(string str)
{
    if (Chats) Chats -= ({ str });
}

void
ev_chat()
{
    /* I let this call out run, even if no chats available */
    /* add/remove chats can then be changed at any point in time */
    if (Chats) tell_room(this_object(), Chats[random(sizeof(Chats))]);
    if (ChatFreq) call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));
}

/* set the frequency for the chats/noise/atmosphere */
void set_chat_frequency(int x) { ChatFreq = x;}
void set_chat_chance(int x) { set_chat_frequency((x > 0) ? 200/x : 0);}
