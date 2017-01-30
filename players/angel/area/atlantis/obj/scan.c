/*                                                                    *
 *    File:             /players/angel/area/atlantis/obj/scan.c       *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/20/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure";

int str;
int them;

reset(arg)
{
   if(arg) return;
   ::reset(arg);
   set_id("scanner");
   set_short(HIW+"A Health Scanner"+NORM);
   set_long("\
This medical scanner allows close scans of a patient's health.\n\
To use, type scan <player>.\n");
   set_weight(1);
   set_value(500);
}

init() {
  ::init();

    add_action("scan", "scan");
}

scan(string str)
{
  string health_msg;
  object them;
  int healthy;

  if(!str)
  {
    write("Scan who?\n");
    return 1;
  }

  them = present(str,environment(this_player()));

  /* test if the object is there, is a player, and is not invis */
  if(!them || !them->is_player() || them->query_invis())
  {
    write("No such player to scan.\n");
    return 1;
  }

  /* dont let people scan wizes. if the person is a wiz themself, only scan higher than themself */
  if(them->query_level() > 19 && them->query_level() > this_player()->query_level())
  {
    write("Wizards don't like to be scanned.\n");
    return 1;
  }

  /* get the PERCENTAGE of hit points they have left */
  healthy = 100 * them->query_hp() / them->query_mhp();

  health_msg = "is near death.";
  if(healthy >= 20)
    health_msg = "is in very bad shape.";
  if(healthy >= 40)
    health_msg = "is in bad shape.";
  if(healthy >= 60)
    health_msg = "could be better.";
  if(healthy >= 80)
    health_msg = "is slightly hurt.";
  if(healthy == 100)
    health_msg = "is in perfect health.";
  write(capitalize(str) + " " + health_msg + "\n");
  say(this_player()->query_name() + " scans " + capitalize(str) + ".\n",them);
  tell_object(them,this_player()->query_name() + " scans you.\n");
  say(capitalize(str) + " " + health_msg + "\n");
  return 1;
}
