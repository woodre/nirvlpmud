/*
 * store.c - A Thrift store
 *           A shop that sells used articles, especially clothing, as to
 *           benifit a charitable organization
 */

#pragma strong_types
#include "./defs.h"
#include <ansi.h>
inherit "/players/rumplemintz/room/color_room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  set_short(RED, "A Thrift Shop");
  set_long(RED, "\
The thrift shop down the road.  This shop sells secondhand goods, such as \n\
clothes, that have been discarded.  Proceeds from stores like this one often\n\
go to benefit a charity.\n");
  set_exit_color(CYN);
  dest_dir = ({
    "players/rumplemintz/workroom", "rump",
    "room/alley", "alley",
  });
  items = ({
    "store", "It's a thrift store...",
  });
}
