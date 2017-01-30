/*
 * Shardak guild (tm) Dragnar + Balowski
 * Ideas for darkness has grown into real darkness
 */
#include "../def.h"
#include "../macros.h"
#include "/players/vertebraker/ansi.h"
#define QUERY_SHADOW 0
#define START_SHADOW 1
#define FUNC(x) status x(string arg) { return shardak_move(arg, "x");}
#define DURATION 30

object          here;           /* the room I am shadowing */
status		strong;

static string
basename(mixed ob)
{
    string fname, no;

    if (objectp(ob)) fname = file_name(ob);
    else if (stringp(ob)) fname = ob;
    else return 0;

    sscanf(fname, "%s#%s", fname, no);
    if (fname[0] != '/') return ("/" + fname);
    return fname;
}

static status
indir(string file, string path)
{
    if (file[0] != '/') file = "/" + file;
    if (path[0] != '/') path = "/" + path;
    return path == file[0 .. strlen(path) - 1];
}

static void
updateroom(object room, status in)
{
    object *obs;
    int i;

    if (room->query_property("fight area")) in = 1;
    i = sizeof(obs = all_inventory(room));
    while (i--) {
	if (in) obs[i]->set_fight_area();
	else obs[i]->clear_fight_area();
    }
}

void
remove_object(object caller)
{
    if (strong) updateroom(here, 0);
    destruct(this_object());
}

object
shardak_darkness(object room)
{
    object      sh;
    int		dur;

    if (objectp(room)) {
	here = room;
	/* shadow returns 'shadowee' if successful */
	if (sh = shadow(room, START_SHADOW)) {
	    strong = indir(basename(room), PATH);
	    dur = DURATION;
	    if (strong) {
		dur *= 3;
		updateroom(room, 1);
	    }
	    call_out("shardak_brightness", dur);
	}
	return sh;
    }
    else {
	/* for remove_shadow() */
	if (strong && this_player() && !servant(this_player())) {
	    write("The sphere of "+BOLD+BLK+"darkness"+NORM+" wavers briefly.\n");
	    tell_room(here, "The sphere of "+BOLD+BLK+"darkness"+NORM+" wavers briefly as " +
		      this_player()->query_name() +
		      " attempts to dispel it.\n", ({ this_player() }));
	    return 0;
	}
	return this_object();
    }
}

static void
shardak_brightness()
{
    tell_room(here, "The "+BOLD+BLK+"darkness"+NORM+" slowly subsides.\n");
    remove_object(this_object());
}

/* This aint allowed as yet
string
realm()
{
}
*/

static status
shardak_move(string arg, string fun)
{
    object op;

  if((string)this_player()->query_guild_name()=="shardak" || (!(this_player()->query_pl_k()) && !(this_player()->query_fight_area())))
  return (status)call_other(here, fun, arg);
/*
    if (strong) {
	if ((int) this_player()->query_attrib("wil") > random(200)) {
	    return (status) call_other(here, fun, arg);
	}
    }
    else {
	if ((op = (object) this_player()->query_attack()) && op->is_player()) {
	    if (random(200) < (int) this_player()->query_attrib("wil")) {
		return (status) call_other(here, fun, arg);
	    }
	}
	else {
	    if (random(30) < (int) this_player()->query_attrib("wil")) {
		return (status) call_other(here, fun, arg);
	    }
	}
    }

*/
    write("An unseen force blocks your exit.\n");
    say("The sphere of "+BOLD+BLK+"darkness"+NORM+
     " blocks " + this_player()->query_name() +
	"'s exit.\n", this_player());
    return 1;
}

/*
 * Will not block all exits, but most exits of /room/room.c
 */
FUNC(move)

/* these will take care of some of the <std.h> exits */
FUNC(move1)
FUNC(move2)
FUNC(move3)
FUNC(move4)

/* these will block some of the differently coded exits */
FUNC(north)
FUNC(south)
FUNC(west)
FUNC(east)
FUNC(out)

FUNC(advance)
FUNC(arena)
FUNC(church)
FUNC(disco)
FUNC(empire)
FUNC(hotel)
FUNC(lockers)
FUNC(market)
FUNC(orin)
FUNC(post)
FUNC(pub)
FUNC(ruins)
FUNC(rift)
FUNC(robomech)
FUNC(shop)
FUNC(tower)
FUNC(victoria)

/*
 * Prepend a little something to the long description
 */
void
long(string item)
{
    if (!item) {
	write("A sphere of impenetrable "+BOLD+BLK+
      "darkness"+NORM+" is enveloping the place.\n");
    }
    here->long(item);
}

void
init()
{
    if(!here) return;
    if (strong) this_player()->set_fight_area();
    here->init();
}

#if 0
void
exit(object x)
{
    /* don't mess with 'get thing' and wizards */
    if (!living(x) || (int) x->query_level() >= 20)
	return;

    /*
     * Rather rude way of blocking exits
     * force runtime error if player is trying to leave room
     * only living::move_player() moves creatures
     */
    if (x != previous_object() || x != this_player() ||
	!query_verb() || query_verb() == "quit")
	return;

    write("An unseen force blocks your exit.\n");
    say("The sphere of "+BOLD+BLK+"darkness"+NORM+
    " blocks " + x->query_name() + "'s exit.\n", x);
    capitalize(0);
}
#endif

status
clean_up(int refcount)
{
    if (!refcount)
	destruct(this_object());
    else
	return 1;       /* try again later */
}


