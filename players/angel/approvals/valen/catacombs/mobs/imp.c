/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/mobs/imp.c           *
 *    Function:         mob                                           *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            mid lvl mob                                   *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object armor;
  ::reset(arg);
  if(arg) return;
  set_name(RED+"Imp"+HIR+" <Demonic>"+NORM);
  set_alt_name("imp");
  set_race(RED+"imp"+NORM);
  set_alias("demon");
  set_short(RED+"Imp"+HIR+" <Demonic>"+NORM);
  set_long(RED+"Imps"+NORM+" are small cunning creatures and rather weak at close combat.\n"+
  "Their strength lies in numbers. "+RED+"Imps"+NORM+" possess a mana leech skill, which\n"+
  "allows them to destroy the magical energy of their enemy. The "+RED+"Imp"+NORM+" has\n"+
  "burning red skin with glowing red eyes. The "+RED+"Imp"+NORM+" has two little horns\n"+
  "on top of its head with a forked tail. The "+RED+"Imp"+NORM+" reeks of sulfur.\n");
  set_level(18);
  set_hp(400  + random (100));
  set_ac(15 + random (4));
  set_wc(26 + random (4));
  set_al(-100);
  add_money(2500);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I have to hide here. A stinking Angel almost killed me!\n");
  load_chat("The "+RED+"Imp"+NORM+" stinks like sulfur.\n");
  load_chat("The "+RED+"Imp"+NORM+" grins evilly!\n");
  armors=clone_object("/players/valen/area/catacombs/armors/d_belt.c");
  move_object(armors, this_object());
  add_spell("mana_leech", "#MN# $HR$LEECHS$N$ magical energy from the room!\n",
                         "#MN# $HR$LEECHES$N$ magical energy from the room!\n",
                         40,0,0,1, "leech_mana");
}

leech_mana(object target, object room, int damage)
{
   target->add_spell_point(-25);
}