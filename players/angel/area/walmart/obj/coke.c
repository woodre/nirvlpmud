/*                                                                            *
 *      File:             /players/angel/area/town/obj/coke.c                 *
 *      Function:         Heal                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)            *
 *                                All Rights Reserved.                        *
 *      Source:           11/20/06                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

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
  set_intox(5);
  set_heal(50,50);
  set_charges(4);
  set_value(1000);
}
query_save_flag() { return 1; }
