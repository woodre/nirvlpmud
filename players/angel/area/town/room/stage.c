/*                                                                            *
 *      File:             /players/angel/area/town/room/stage.c               *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("customer", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/customer.c"), this_object());
  if( !present("multi02", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi_02.c"), this_object());
  if( !present("multi", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/multi.c"), this_object());
  if( !present("burglar", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/burglar.c"), this_object());
  if( !present("grimace", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/grimace.c"), this_object());
  if( !present("ronald", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/ronald.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Stage";
  long_desc =
"  This is a portable stage that pops up and down quickly.\n\
Ronald and his friends use it to travel around the country\n\
to put on magic shows!  Children love to see Ronald and his\n\
friends.\n";

  items =
  ({
	"stage",
	"A portable, small stage",
	"shows",
	"A unique display of trickery",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/mcdonalds.c",      "counter",
  });
}