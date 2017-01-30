/*
 * Shardak guild - (tm) Dragnar/John
 * Grotto is (c) Balowski/Rasmus, March 12th 1995.
 * The main guild room. From here you can go many places
 * log
 * 950318 - something
 * 950421 - ROOM
 * 2000 - fixed board, 'in' exit.
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../people.h"
#define VBOARD "/players/vertebraker/closed/misc/board2"

inherit ROOM;

void
create()
{
    ::create();
    if(!present("notice")) move_object(clone_object("/players/feldegast/obj/pkobit"), this_object());
    set_short("A grotto");
    set_long("\
A number of narrow galleries lead into an expanding grotto. Deep below\n\
the earth's surface the icy tentacles of the moisture laden air stabs\n\
at your flesh, leaving you shivering. The flickering light of torches\n\
illuminate the stalactites hanging from the ceiling. Huge stalagmites\n\
have turned the grotto into a maze of galleries and smaller rooms.\n\
A narrow crevice leads into the portals.\n\
You see five exits: west, northeast, north, east, up, and down.\n");

    set_items( ([
({ "stalactites", "stalagmites" }) : "\
Water saturated with lime has been dripping from the ceiling over\n\
the centuries, slowly growing icicle-like stalactites and thick\n\
stalagmites on the floor. On the walls the seeping water has formed\n\
weird fungi-resembling shapes.\n",
({ "crevice", "narrow crevice" }) : "\
A narrow, dark crevice that you may pass 'in' to get to the\n\
dark area of Portals.\n",
    ]));
    set_exits(([
        "up" :          (PATH + "cave"),
        "down" :        (PATH + "descent"),
        "northeast" :   (PATH + "smithy"),
        "east" :        (PATH + "shop"),
         "north" :        (PATH + "othrone"),
        "west" :        (PATH + "advance"),
        "in" :          (PATH + "portals"),
        ]));
    set_light(1);
    set_property("fight area", 1);
    set_property("no teleport", 1);
}

status
allow_read(object who)
{
    if (who && (string) who->query_guild_name() == GUILDNAME) return 1;
}

void 
reset(int arg)
{
    object          board;

    ::reset(arg);
    /*
    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("servants");
        board->set_size(50);
        board->set_short("A board is fixed on a nearby stalagmite");
        board->set_editors(LAW);
        board->set_readers(symbol_function("allow_read", this_object()));
        move_object(board, this_object());
    }
    */
}
