/*                                                                            *
 *      File:             /players/angel/area/town/obj/emm.c                  *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        3 use heal that splits 10 tox: 5 soak, 5 stuff      *
 *                        heals for 50 hps and 50 sps each use / 50 heal pts  *
 *                        heals for 150 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (10*3)/(50*3)  = .20 = 16/pt. = 150*16  = 2400  *
 *                          Purchase in McDonald's                            *
 *                          town/room/mcdonalds.c                             *
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
  set_name("egg mcmuffin");
  add_alias("egg");
  add_alias("mcmuffin");
  add_alias("muffin");
  set_short(HIR+"["+HIY+"Egg McMuffin"+HIR+"]"+NORM);
  set_long("Grade A egg, Canadian-style bacon, slice of\n\
American cheese on a toasted English muffin.\n");
  set_type("bites");
  set_type_single("bite");
  set_msg("You place the Egg McMuffin in your mouth and it melts!\n");
  set_msg2(" melts as its mouth sink into the sandwich!\n");
  add_cmd("bite");
  set_heal(50,50);
  set_charges(3);
  set_soak(5);
  set_stuff(5);
  set_value(500);
}

query_save_flag() { return 1; }
