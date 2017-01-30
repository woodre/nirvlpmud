/*                                                                    *
 *    File:             /players/angel/area/atlantis/npc/sheppard.c   *
 *    Function:         npc                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           10/05/07                                      *
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
  set_name("sheppard");
  set_alt_name("john");
  set_race("military");
  set_alias("major");
  set_short(""+HIG+"John Sheppard"+NORM+"");
  set_long(
  "John is a Major in the United States military and a highly\n"+
  "skilled pilot with a checkered past.  He leads the base's\n"+
  "flagship reconnaissance team in exploring other worlds through\n"+
  "the Stargate.  He possesses the rare gene that allows him to\n"+
  "use Ancient technology.\n");
  set_level(20);
  set_hp(500);
  set_ac(17);
  set_wc(30);
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(100)+4000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  command("unwield P90", this_object());
  set_chat_chance(12);
  set_a_chat_chance(12);
  load_chat("How about we go watch a game and get some popcorn!\n");
  load_chat("What's the status on that?\n");
  load_a_chat("They're politicians, Rodney. They're all creepy.\n");
  add_spell("shot","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                   "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                    25,30,"other|physical");
}