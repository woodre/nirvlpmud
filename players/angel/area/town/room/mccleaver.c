/*                                                                            *
 *      File:             /players/angel/area/town/room/mccleaver.c           *
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
    move_object(clone_object("/players/angel/area/town/npc/cashier_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Mc Cleaver's";
  long_desc =
"    "+HIB+"McCleaver's Gas Station"+NORM+"\n\
  Mr. McCleaver's privately owned station has two islands covered\n\
with canopies.  The garage has two bays and an office.  There\n\
is a soda pop machine next to the garage.\n";

  items =
  ({
	"station",
	"A small business that sell gas",
	"islands",
	"An area that is covered by a canopy",
	"canopies",
	"A large roof on two poles to stop rain and sun coming down",
	"garage",
	"It has two bays to work on cars",
	"bays",
	"An open area to work on cars",
	"office",
	"There is a messy desk with a phone sitting on top",
	"machine",
	"There is a sign taped to the machine that says it is out of order",
  });
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_08",     "road",
  });
}