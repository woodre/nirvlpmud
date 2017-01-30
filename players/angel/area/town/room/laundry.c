/*                                                                            *
 *      File:             /players/angel/area/town/room/laundry.c             *
 *      Function:         room                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
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
  if( !present("cashier", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/cashier.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Laundromat";
  long_desc =
"    "+HIB+"Laundromat"+NORM+".\n\
  Main Street Laundry, located at 331 East Main Street\n\
is a large, clean facility that is designed to provide\n\
the best wash in the area. Its equipped with 32 washers,\n\
32 dryers, and top of the line equipment. The system is\n\
the most state of the art in the entire land. There are\n\
two televisions in the laundromat, including Sun Quenchers\n\
a tanning salon with top of the line beds.\n";

  items =
  ({
	"washers",
	"They're top of the line",
	"dryers",
	"They're top of of the line",
	"televisions",
	"Both tv's are 26' flat screens hung on the wall",
	"salon",
	"It is a small area with 4 tanning beds in small rooms inside of the laundry mat",
	"beds",
	"8ft long tanning beds",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/hw_355",     "highway",
  });
}