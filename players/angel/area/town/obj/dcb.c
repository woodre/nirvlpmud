/*                                                                            *
 *      File:             /players/angel/area/town/obj/dcb.c                  *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        3 use heal that splits 12 tox: 6 soak, 6 stuff      *
 *                        heals for 50 hps and 50 sps each use / 50 heal pts  *
 *                        heals for 150 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (12*3)/(50*3)  = .24 = 14/pt. = 150*14  = 2100  *
 *                          Purchase in McDonald's                            *
 *                          town/room/mcdonalds.c                             *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include <ansi.h> 

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cheeseburger");
  add_alias("burger");
  add_alias("cheeseburger");
  add_alias("cheese");
  set_short(HIR+"["+HIB+"Double Cheeseburger"+HIR+"]"+NORM);
  set_long("This is juicy Double Cheeseburger Two all beef patties with\n\
two slices of American cheese, pickle, onions, ketchup, and mustard on\n\
a toasted bun.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("As the burger gets close, your mouth begins to water.   Yummy!\n");
  set_msg2(" bites through the juicy burger as your mouth begins to water.\n");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(3);
  set_soak(6);
  set_stuff(6);
  set_value(400);
}

query_save_flag() { return 1; }