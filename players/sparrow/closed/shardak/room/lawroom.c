#define VBOARD "/players/vertebraker/closed/misc/board2"

/*
 * A special room for the law enforcers of the guild
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../def.h"
#include "../people.h"

inherit ROOM;

void
create()
{
    ::create();
    set_short("The Law Enforcers' meeting hall");
    set_long("\
You are in a cubical cave. There is nothing here, no furniture, no\n\
decorations. In fact, only Shardak's law enforcers should enter this\n\
room as this is where they hold deliberations.\n\
\tYou see one exit and that is going west.\n");
    set_items(([
    ]));
    set_exits(([
        "west" :        (PATH + "throne"),
        ]));
    set_light(1);
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
        board->set_name("law_enf");
        board->set_size(50);
        board->set_short("A board is fixed on the wall");
        board->set_editors(LAW);
        board->set_readers(symbol_function("allow_read", this_object()));
        move_object(board, this_object());
    }
    */
}
