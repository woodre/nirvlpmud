/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/landry.c     *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           1/5/06                                        *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
 
#include "/sys/lib.h"
 
#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("major general hank landry");
  set_alt_name("landry");
  set_race("military");
  set_alias("general");
  set_short("Major General Hank Landry");
  set_long("\
  Major General Hank Landry, a straight-talking and get-to-the-point\n\
military leader. Landry took over the position from Jack O'Neill\n\
around the time that SG-1 disbanded, and its members moved on to\n\
new assignments. \n");
  set_level(20);
  set_hp(500 + random (100));
  set_ac(17 + random (5));
  set_wc(30 + random (5));
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(500)+5000);
  move_object(gold, this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \"Damit, I have to call the President again!\"\n");
  load_chat("I need a vacation!\n");
  add_spell("P90","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}