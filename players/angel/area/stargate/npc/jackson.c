/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/jackson.c    *
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
  set_name("daniel jackson");
  set_alt_name("jackson");
  set_race("military");
  set_alias("daniel");
  set_short("Dr. Daniel Jackson");
  set_long("\
  SG-1's archaeological expert, responsible for cracking the code\n\
to first activate the Stargate. A student of language, mythology\n\
and ancient cultures, Jackson's knowledge and razor-sharp wit is\n\
key to encounters with alien civilizations and displaced human\n\
colonies across the galaxy. Sometimes awkward, sometimes socially\n\
inept, he is driven, intelligent, and an invaluable member of the\n\
Stargate program.\n");
  set_level(22);
  set_hp(700 + random (100));
  set_ac(20 + random (7));
  set_wc(38 + random (7));
  set_al(0);
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+5000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/stargate/obj/P90_no_ammo.c");
  move_object(armor, this_object());
  weapon=clone_object("/players/angel/area/stargate/obj/bullets.c");
  move_object(weapon, this_object());
  command("load P90", this_object());
  set_chat_chance(5);
  load_chat(query_name()+" says, \" Wow, I can't beleive I just found Atlantis!\"\n");
  load_chat(" It pays off to know so many different languages!\n");
  add_spell("P90","#MN# shoots his $HR$P-90$N$ piercing you.\n",
                     "#MN# shoots his $HR$P-90$N$ piercing #TN#.\n",
                     75,30,"other|physical");
}