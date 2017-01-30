/*                                                                            *
 *      File:             /players/angel/area/town/obj/fries.c                *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
  *                   based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        4 use heal that splits 12 tox: 6 soak, 6 stuff      *
 *                        heals for 40 hps and 40 sps each use / 40 heal pts  *
 *                        heals for 120 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (12*4)/(40*4)  = .30 = 12/pt. = 160*12  = 1920  *
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
  set_name("fries");
  add_alias("fry");
  add_alias("frence fries");
  set_short(HIR+"["+HIY+"French fries"+HIR+"]"+NORM);
  set_long("Golden, long, thin, perfectly salted fries that are\n\
crisp on the outside, tender inside with a great potato taste.\n");
  set_type("fries");
  set_type_single("fry");
  set_msg("America's favorite fries! umm....\n");
  set_msg2(" bites down and get that great potato taste!\n");
  add_cmd("bite");
  set_heal(40,40);
  set_charges(4);
  set_soak(6);
  set_stuff(6);
  set_value(320);
}

query_save_flag() { return 1; }