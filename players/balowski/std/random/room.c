/*
 * Room thingy for 3.1.2-DR, Balowski@Nirvana
 */
#include "/players/balowski/lib.h"
#pragma strict_types
#pragma save_types
inherit BASE;

#undef SPARRING                 /* needed 1 out of 10000 */

private string  RoomShort;      /* brief description */
private string  RoomLong;       /* Long description of the room */
private mapping Items;          /* lookables */
private int     MaxCastles;     /* allow castle drop? */
private status  NoClean;        /* set to stop self destruct on idle */
private string	*Chats;
private int	ChatFreq, Players;
inherit GENERATE;
inherit SIGNS;
inherit ATMOS;
inherit PROPS;
inherit EXITS;

void create()
{
    Items = ([ ]);
    exits::create();
    signs::create();
    atmos::create();
    props::create();
}

status id(string str)
{
    /* I've decided that you can look at the signs directly */
    return (Items[str] || signs::id(str));
}

string short()
{
    if (set_light(0) <= 0) return "Dark room";
    return RoomShort;
}

/*
 * Multi purpose function used by the mudlib
 * Called with no arg whenever player does 'look'
 * Called with <x>, if player does 'look at <x>' and id(<x>) returns true
 */
void long(string str)
{
    string s;

    if (set_light(0) <= 0)
       write("It is dark.\n");
    else {
	if (str) {
	    if (s = Items[str]) {
		if (closurep(s)) s = funcall(s, str);
		if (stringp(s)) write(s);
	    }
	    else if (query_sign(str)) {
		/*write("You should read it.\n");*/
		cmd_read(str);
	    }
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
void init()
{
#ifdef SPARRING
    if (this_player()->is_player() && (int) this_player()->query_pl_k() < 2) {
	this_player()->move_player("X#/room/void");
    }
#endif
    if (query_property("fight area")) {
	this_player()->set_fight_area();
    }
    if (this_player()->is_player()) Players++;
    if (Players == 1) {
	if (ChatFreq) call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));
	StartGenerator();
    }
    /* shiver! */
    atmos::init();
    signs::init();
    exits::init();
}

/*
 * Applied by the driver whenever an object if removed from here
 */
void
exit(object ob)
{
    if (ob->is_player()) {
	if (!--Players) {
	    remove_call_out("ev_chat");
	    StopGenerator();
	}
	if (query_property("fight area"))
	    ob->clear_fight_area();     /* not really necessary.. */
#ifdef SPARRING
	if (query_property("spar area"))
	    ob->rm_spar();              /* removes sparring flag, if set */
#endif
    }
}

/*
 * The long description of the room,
 * The command look should show this
 */
void set_long(mixed str)
{
    RoomLong = str;
}

string query_long()
{
    return RoomLong;
}

/*
 * The short description of the room should be one line,
 * without newline. It is for players with brief set on
 */
void set_short(string s)
{
    RoomShort = s;
}

string query_short()
{
    return RoomShort;
}

/*
 * Items to look at .. more or less pinched from foundation
 * piffed up a little, but I don't like all these if's and while's
 * Changable on the fly!
 */
void add_item(mixed id, string desc)
{
    int         j;

    if (pointerp(id)) {
	j = sizeof(id);
	while (j--) Items[id[j]] = desc;
    }
    else Items[id] = desc;
}

void set_items(mapping m)
{
    int         i, j;
    mixed       *ks;

    i = sizeof(ks = m_indices(m));
    while (i--) add_item(ks[i], m[ks[i]]);
}

void remove_item(mixed id)
{
    int         j;

    if (pointerp(id)) {
	j = sizeof(id);
	while (j--) m_delete(Items, id[j]);
    }
    else m_delete(Items, id);
}

/*
 * Here goes some of the Nirvana oddities.
 * The realm function should be checked before teleporting players
 * If query_spar_area returns non-zero, players don't lose xp on death
 * The fight area thing allows for pk fights
 */
string realm()
{
    return (query_property("no teleport") ?
	    "NT" : (query_property("no follow") ?
		    "LA" : 0));
}

#ifdef SPARRING
mixed query_spar_area()
{
    return (query_property("spar area"));
}
#endif

/*
 * This determines if wizard can drop castles here
 * default is 0, which means not allowed
 */
void set_max_castles(int value)
{
    MaxCastles = value;
}

int query_drop_castle()
{
    return MaxCastles;
}

void set_no_clean(status stop)
{
    NoClean = stop;
}

/*
 * This baby needs work
 * It isn't called often though
 */
int clean_up(int refcount)
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
    return 1; /* Rumplemintz */
}

/*
 * Chat stuff.. quite like monsters
 */
void load_chats(string *strs)
{
    if (!Chats)	Chats = strs;
    else Chats += strs;
}

void load_chat(string str) { load_chats(({ str }));}

/*
 * Remove a previously loaded chat string.
 * First occurrence matching 'str' will be removed from array
 */
void remove_chat(string str)
{
    if (Chats) Chats -= ({ str });
}

void ev_chat()
{
    /* I let this call out run, even if no chats available */
    /* add/remove chats can then be changed at any point in time */
    if (Chats) tell_room(this_object(), Chats[random(sizeof(Chats))]);
    if (ChatFreq) call_out("ev_chat", (ChatFreq >> 1) + random(ChatFreq));
}

/* set the frequency for the chats/noise/atmosphere */
void set_chat_frequency(int x) { ChatFreq = x;}
void set_chat_chance(int x) { set_chat_frequency((x > 0) ? 200/x : 0);}
