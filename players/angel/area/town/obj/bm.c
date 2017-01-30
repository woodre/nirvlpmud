/*                                                                            *
 *      File:             /players/angel/area/town/obj/bm.c                   *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        4 use heal that splits 8 tox: 4 soak, 4 stuff       *
 *                        heals for 50 hps and 50 sps each use / 50 heal pts  *
 *                        heals for 200 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (8*4)/(50*4)  = .16 = 18/pt. = 200*18  = 3600   *
 *                          Purchase in McDonald's                            *
 *                          town/room/mcdonalds.c                             *
 *      Change History:                                                       *
 */

#include <ansi.h> 
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("big mac");
  add_alias("mac");
  add_alias("burger");
  set_short(HIR+"["+HIM+"Big Mac"+HIR+"]"+NORM);
  set_long("This is a juicy Big Mac. Two all beef patties, special sauce,\n\
lettuce, cheese, pickles, onions on a sesame seed bun.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("The large Big Mac is putting out a desirable aroma!\n");
  set_msg2(" bites through the juicy burger as your mouth begins to water.\n");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(4);
  set_soak(4);
  set_stuff(4);
  set_value(900);
}

query_save_flag() { return 1; }