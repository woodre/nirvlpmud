/*
 *    File: /players/chip/mobs/apartment/hman1.c
 *    Function: NPC
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes:
 *
 *
 *    Change History:
 */

#include "/sys/lib.h"

#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("man");
  set_race("human");
  set_alias("man");
  set_short(""+HIW+"A dirty, homeless man"+NORM+"");
  set_long(
         "A very unkempt man stands before you. A foul odor of\n"+
         "urine and vomit emits from him, even at a distance. He\n"+
         "looks to be blind in one eye, and walks with a limp.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(0);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The man sobs deeply as he remembers better days.\n");
  load_chat("The man says: \"I wish I would have done things differently...\"\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The dirty man flings a dead rat at you.\n");
  set_spell_mess1("The dirty man flings a dead rat at his attacker.\n");
  move_object("/players/chip/items/apartment/cheeseburger.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int frenchfries;
      frenchfries = random(5) + 2; 
      while (frenchfries > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/frenchfries.c"), this_object());
         frenchfries--;
      }
   }
