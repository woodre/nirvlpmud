/*                                                                            *
 *      File:             /players/angel/area/town/obj/sp.c                   *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        3 use heal that splits 6 tox: 3 soak, 3 stuff       *
 *                        heals for 30 hps and 30 sps each use / 30 heal pts  *
 *                        heals for 90 total 'heal pts'                       *
 *                        COST =                                              *
 *                            (6*3)/(30*3)  = .20 = 16/pt. = 90*16  = 1440    *
 *                          Purchase in Double Davis                          *
 *                          town/room/daves.c                                 *
 *                                                                            *
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
  set_name("small pizza");
  add_alias("pizza");
  add_alias("small");
  set_short(HIW+"["+HIR+"Small Pizza"+HIW+"]"+NORM);
  set_long("This is a small thin crust pepperoni pizza.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("The small pepperoni pizza is putting out a desirable aroma!\n");
  set_msg2(" bites through the hot pizza as its mouth begins to water.\n");
  add_cmd("bite");
  set_heal(30,30);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(1000);
}

query_save_flag() { return 1; }
