/*                                                                            *
 *      File:             /players/angel/area/town/room/bank.c                *
 *      Function:         Room                                                *
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
  if( !present("teller", this_object()) )
    move_object(clone_object("/players/angel/area/town/npc/teller.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Farmers City Bank";
  long_desc =
"    "+HIB+"Farmers City Bank"+NORM+"\n\
  Farmers City Bank has completed its restoration project. In keeping\n\
with community emphasis on historic restoration, the front lobby and\n\
vestibule have been returned as closely as possible to the way they\n\
looked one hundred years ago.  Stenciling work in the manner of the\n\
late nineteenth century decorates the walls, and the original majestic\n\
front doors have been duplicated.  The town's citizens can use the\n\
bank to make deposits and withdraws.\n";

  items =
  ({
	"lobby",
	"A place of commerce for the townspeople",
	"vestibule",
	"It is a large entrance to the lobby",
	"walls",
	"Gold stenciling, in the form of tiny fleur-de-lis and lacework,\n\
	 enhance the borders and give a formal appearance",
	"doors",
	"Large majestic oak doors",
	"work",
	"Itinerant artist move with eligance to complete the wall",
	"stenciling",
	"Itinerant artist move with eligance to complete the wall",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/main_01",     "road",
  });
}