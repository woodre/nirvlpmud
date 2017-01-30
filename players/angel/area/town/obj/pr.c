/*                                                                            *
 *      File:             /players/angel/area/town/obj/pr.c                   *
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
 *                          Purchase in Double Daves                          *
 *                          town/room/daves.c                                 *
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
  set_name("pizza roll");
  add_alias("roll");
  add_alias("pizza");
  set_short(HIW+"["+HIR+"Pizza Roll"+HIW+"]"+NORM);
  set_long("This is long round roll filled with pepperoni, cheese, and sauce.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("The pepperoni roll is putting out a desirable aroma!\n");
  set_msg2(" bites through the pizza roll as your mouth begins to water.\n");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(4);
  set_soak(4);
  set_stuff(4);
  set_value(900);
}

query_save_flag() { return 1; }