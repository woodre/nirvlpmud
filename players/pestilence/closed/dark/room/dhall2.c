/*
 * Shardak guild - (tm) Dragnar/John
 * Grotto is (c) Balowski/Rasmus, March 12th 1995.
 * The main guild room. From here you can go many places
 * log
 * 950318 - something
 * 950421 - ROOM
 * 2000 - fixed board, 'in' exit. Used with Vertebrakers Permission
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "/players/vertebraker/closed/shardak/def.h"
#include "/players/pestilence/ansi.h"
#define VBOARD "/players/pestilence/closed/misc/board2"

inherit ROOM;

void
create()
{
    ::create();
    set_short(""+HIK+"Main Entrance"+NORM+"");
    set_long("\
    This is a large cave where the board is keeped for the Dark Order.\n\
The room has been carved into the rocks of a very deep cave.  To\n\
the east there is a tunnel that leads out of the cave.\n\
    There is one obvious exit: east.\n");

    set_items( ([
({ "rocks", "large rocks" }) : "\
Large rocks that surround everything.\n",
({ "cave", "dark cave" }) : "\
A large cave leading to the east.\n",
    ]));
    set_exits(([
        "east" :          ("/players/pestilence/closed/dark/room/dhall.c"),
        "north" :          ("/players/pestilence/closed/dark/room/shop.c"),
        "south" :          ("/players/pestilence/closed/dark/room/smith2.c"),
        ]));
    set_light(-6);
    set_property("fight area", 1);
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
        board->set_short("A board placed in the middle of the cave.");
        move_object(board, this_object());
    }
}
