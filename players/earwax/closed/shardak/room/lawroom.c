/*
 * A special room for the law enforcers of the guild
 * 030715 - Added color, exits viewable by shardaks only,
 * and tweaked the desc [linus]
 */
#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/people.h"
#include "../include/ansi.h"
#define VBOARD "/players/earwax/closed/misc/board2"

inherit ROOM;

void
create()
{
    ::create();
    set_short(RED+"The Law Enforcers' meeting hall"+NORM);
    set_items(([
    ]));
    set_exits(([
        "west" :        (PATH + "throne"),
        ]));
    set_light(1);
}

/* Long description and exit shit */
void
long(string arg) {
 string desc;
 desc = "";
  if((int)this_player()->query_brief() != 2) 
   desc += RED+"The Law Enforcers' meeting hall\n"+NORM;
   desc += HIK+"\
There is nothing in this cave, no furnirture, no decorum,\n\
nothing. In fact, only Shardak's law enforcers should enter this\n\
room as this is where they hold deliberations.\n"+NORM;

/* Not sure why I'm putting this check in since ONLY shardaks are allowed
 * here, heh 
 */

 if (present("shardak_mark",this_player())) {
  desc += "\t"+NORM+RED+"\The only exit is: west.\n"+NORM;
  }
 write(desc);
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
    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("law_enf");
        board->set_size(50);
        board->set_short("A board is fixed on the wall");
        board->set_editors(LAW);
        board->set_readers(symbol_function("allow_read", this_object()));
        move_object(board, this_object());
    }
}




