/*                                                                            *
 *      File:             /players/angel/area/town/obj/lp.c                   *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        3 use heal that splits 6 tox: 3 soak, 3 stuff       *
 *                        heals for 50 hps and 50 sps each use / 50 heal pts  *
 *                        heals for 150 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (6*3)/(50*3)  = .12 = 22/pt. = 150*22  = 3300   *
 *                          Purchase in Double Daves                          *
 *                          town/room/daves.c                                 *
 *                                                                            *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("large pizza");
  add_alias("pizza");
  add_alias("large");
  set_short(HIW+"["+HIR+"Large Pizza"+HIW+"]"+NORM);
  set_long("This is a large deep dish pepperoni and mushroom pizza\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("The large pizza is putting out a desirable aroma!\n");
  set_msg2(" bites through the hot pizza as your mouth begins to water.\n");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(1000);
}

query_save_flag() { return 1; }