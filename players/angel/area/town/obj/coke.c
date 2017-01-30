/*                                                                            *
 *      File:             /players/angel/area/town/obj/coke.c                 *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                    based on cost from doc/build/items/heals/heals1 /heals3 *
 *                        4 use heal that use 12 tox: 12 soak                 *
 *                        heals for 50 hps and 50 sps each use / 50 heal pts  *
 *                        heals for 200 total 'heal pts'                      *
 *                        COST =                                              *
 *                            (12*4)/(50*4)  = .24 = 14/pt. = 200*14  = 2800  *
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
  set_name("coke");
  add_alias("bottle");
  add_alias("drink");
  add_alias("soda");
  set_short(HIB+"["+MAG+"Coke"+HIB+"]"+NORM);
  set_long("A large 24oz tall glass of coke.\n");
  set_type("bottles");
  set_type_single("bottle");
  set_msg(" you feel refreshed as the carmel flavor flows smoothly down!\n");
  set_msg2(" feels refreshed as the carmel flavor flows smoothly down!\n");
  add_cmd("drink");
  set_heal(50,50);
  set_charges(4);
  set_soak(12);
  set_value(400);
}
query_save_flag(){

  return 1;
  }
