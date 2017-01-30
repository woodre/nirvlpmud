/*
 * Shardak guild - (tm) Dragnar/John
 * Grotto is (c) Balowski/Rasmus, March 12th 1995.
 * The main guild room. From here you can go many places
 * log
 * 950318 - something
 * 950421 - ROOM
 * 2000 - fixed board, 'in' exit.
 * 030719 - Added color, tweaked desc, added checks for brief and
 *          guild obj to display exits. [linus]
 */

#pragma strict_types
#include "/players/balowski/lib.h"
#include "../include/def.h"
#include "../include/people.h"
#include "../include/ansi.h"
#define VBOARD "/players/earwax/closed/misc/board2"

inherit GHALL;

void
on_create()
{
  if(!present("notice")) move_object(clone_object("/players/feldegast/obj/pkobit"), this_object());
  set_short(RED+"The grotto"+NORM);
  set_long(HIK+"\
A number of narrow galleries lead into an expanding grotto. Deep below\n\
the earth's surface the icy tentacles of the moisture laden air stabs\n\
at the flesh.  Flickering light of torches illuminate the stalactites\n\
that hang from the ceiling.  Huge stalagmites have turned the grotto\n\
into a maze of galleries and smaller rooms.  A narrow crevice leads\n\
into the portals.\n"+NORM);
  add_item("stalactites","\
Water saturated with lime has been dripping from the ceiling over\n\
the centuries, slowly growing icicle-like stalactites and thick\n\
stalagmites on the floor. On the walls the seeping water has formed\n\
weird fungi-resembling shapes.\n");
  add_item("stalagmites","\
Water saturated with lime has been dripping from the ceiling over\n\
the centuries, slowly growing icicle-like stalactites and thick\n\
stalagmites on the floor. On the walls the seeping water has formed\n\
weird fungi-resembling shapes.\n");
  add_item("crevice","\
A narrow, dark crevice that you may pass 'in' to get to the\n\
dark area of Portals.\n");
add_item("narrow crevice","\
A narrow, dark crevice that you may pass 'in' to get to the\n\
dark area of Portals.\n");
  add_exit("up",PATH+"cave");
  add_exit("down",PATH+"descent");
  add_exit("northeast",PATH+"smithy");
  add_exit("east",PATH+"shop");
  add_exit("west",PATH+"advance");
  add_exit("in",PATH+"portals");
  set_property("fight area", 1);
  set_property("no teleport", 1);
}

status
allow_read(object who)
{
    if (who && (string) who->query_guild_name() == GUILDNAME) return 1;
}

void 
on_reset()
{
    object          board;

    if (!present("bulletin board")) {
        board = clone_object(VBOARD);
        board->set_name("servants");
        board->set_size(50);
        board->set_short("The Shardak Bulletin Board is here");
        board->set_editors(LAW);
        board->set_readers(symbol_function("allow_read", this_object()));
        move_object(board, this_object());
    }
}
