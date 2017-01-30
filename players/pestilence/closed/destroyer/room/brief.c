#pragma strict_types
#include "/players/balowski/lib.h"
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/pestilence/ansi.h"
#define VBOARD "/players/pestilence/closed/misc/board"

inherit ROOM;

void
create()
{
    ::create();
    set_short(""+YEL+"Debriefing Room"+NORM+"");
    set_long("\
    This is a large room where members of the Army come to discuss\n\
past and future missions.  Also to gather information to help\n\
them in the future.\n\
    There is one obvious exit: north.\n");

    set_items( ([
({ "rocks", "large rocks" }) : "\
Large rocks that surround everything.\n",
({ "cave", "dark cave" }) : "\
A large cave leading to the east.\n",
    ]));
    set_exits(([
        "north" :          ("/players/pestilence/closed/destroyer/room/hall.c"),
        ]));
    set_light(1);
    set_property("no teleport", 1); 
}

status
allow_read(object who)
{
    if (who && (string) who->query_guild_name() == "Dark Order") return 1;
}


void 
reset(int arg)
{
    object          board;

    ::reset(arg);
    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("servants");
        board->set_size(50);
        board->set_short("The "+YEL+"Army"+NORM+" Board.");
        move_object(board, this_object());
    }
}
